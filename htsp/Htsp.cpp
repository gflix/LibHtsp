#include <htsp/Autoconf.h>
#include <sstream>
#include <stdexcept>
#include <glisseo/utils/Select.h>
#include <htsp/HtspTags.h>
#include <htsp/Htsp.h>
#include <htsp/HtspClientMethodAutorecEntryAdd.h>
#include <htsp/HtspClientMethodChannelAdd.h>
#include <htsp/HtspClientMethodDvrEntryAdd.h>
#include <htsp/HtspClientMethodDvrEntryUpdate.h>
#include <htsp/HtspClientMethodInitialSyncCompleted.h>
#include <htsp/HtspClientMethodTagAdd.h>
#include <htsp/HtspClientMethodTagUpdate.h>

#ifndef PACKAGE_STRING
#define PACKAGE_STRING "unknown"
#endif

#define HTSP_TCP_PORT_DEFAULT (9982)
#define HTSP_BUFFER_SIZE (65536)

namespace Flix {

Htsp::Htsp()
{
}

Htsp::~Htsp()
{
    disconnect();
}

void Htsp::connect(const std::string& host, int port)
{
    resetReceiveBuffer();
    tcpClient.connect(host, port);
}

void Htsp::disconnect(void)
{
    tcpClient.disconnect();
    resetReceiveBuffer();
}

bool Htsp::isConnected(void) const
{
    return
        tcpClient.isConnected();
}

int Htsp::getDescriptor(void) const
{
    return
        tcpClient.getDescriptor();
}

HtspMethodAuthenticateResponse Htsp::performMethodAuthenticate(const HtspMethodAuthenticateRequest& request)
{
    HtspMethodAuthenticate htspMethodAuthenticate(request, authenticationChallenge);

    execute(htspMethodAuthenticate);

    return htspMethodAuthenticate.getResponse();
}

void Htsp::performMethodEnableAsyncMetadata(const HtspMethodEnableAsyncMetadataRequest& request)
{
    HtspMethodEnableAsyncMetadata htspMethodEnableAsyncMetadata(request);

    execute(htspMethodEnableAsyncMetadata);
}

HtspMethodHelloResponse Htsp::performMethodHello(const HtspMethodHelloRequest& request)
{
    HtspMethodHello htspMethodHello(request);

    execute(htspMethodHello);

    HtspMethodHelloResponse response = htspMethodHello.getResponse();
    authenticationChallenge = response.challenge;

    return response;
}

void Htsp::execute(GenericHtspMethod& method)
{
    sendMessage(method.getRequestMessage());

    Glisseo::Select select;
    select.addReadDescriptor(getDescriptor());
    select.setTimeout(15);

    if (select.execute() <= 0)
    {
        throw std::runtime_error("timed out reading from server");
    }

    HtspMessages htspMessages;
    receiveMessages(htspMessages);
    method.setResponseMessages(htspMessages);
}

void Htsp::sendMessage(const HtspMessage& message)
{
    tcpClient.send(message.getEncoded());
}

void Htsp::sendMessages(const HtspMessages& messages)
{
    for (auto& message: messages)
    {
        sendMessage(message);
    }
}

void Htsp::receiveMessages(HtspMessages& messages)
{
    std::string encoded;

    tcpClient.receive(encoded, HTSP_BUFFER_SIZE);
    appendReceivedData(encoded);

    getMessages(messages);
}

void Htsp::appendReceivedData(const std::string& receivedData)
{
    receiveBuffer += receivedData;
}

void Htsp::resetReceiveBuffer(void)
{
    receiveBuffer.clear();
}

bool Htsp::hasMessage(void) const
{
    size_t receiveBufferLength = receiveBuffer.size();
    if (receiveBufferLength < 4)
    {
        return false;
    }
    size_t messageLength = getLength(receiveBuffer.substr(0, 4));

    return
        receiveBufferLength >= messageLength + 4;
}

void Htsp::getMessages(HtspMessages& messages)
{
    messages.clear();

    while (hasMessage())
    {
        size_t messageLength = getLength(receiveBuffer.substr(0, 4));
        receiveBuffer.erase(0, 4);

        HtspMessage message;
        message.setEncoded(receiveBuffer.substr(0, messageLength));
        receiveBuffer.erase(0, messageLength);

        messages.push_back(std::move(message));
    }
}

size_t Htsp::getLength(const std::string& value) const
{
    if (value.size() != 4)
    {
        throw std::invalid_argument("invalid argument");
    }

    size_t length = 0;
    for (int i = 0; i < 4; ++i)
    {
        length = (length << 8) | static_cast<unsigned char>(value[i]);
    }

    return length;
}

void Htsp::getClientMethods(HtspMessages& messages, HtspClientMethods& clientMethods)
{
    std::stringstream stream;
    clientMethods.clear();

    for (auto it = messages.begin(); it != messages.end();)
    {
        if (!it->hasField(HTSP_ID_METHOD))
        {
            ++it;
            continue;
        }

        std::string method = it->getField(HTSP_ID_METHOD)->toString();
        HtspClientMethod clientMethod;

        if (method == HTSP_METHOD_TAG_ADD)
        {
            clientMethod.reset(new HtspClientMethodTagAdd(*it));
        }
        else if (method == HTSP_METHOD_TAG_UPDATE)
        {
            clientMethod.reset(new HtspClientMethodTagUpdate(*it));
        }
        else if (method == HTSP_METHOD_CHANNEL_ADD)
        {
            clientMethod.reset(new HtspClientMethodChannelAdd(*it));
        }
        else if (method == HTSP_METHOD_AUTOREC_ENTRY_ADD)
        {
            clientMethod.reset(new HtspClientMethodAutorecEntryAdd(*it));
        }
        else if (method == HTSP_METHOD_DVR_ENTRY_ADD)
        {
            clientMethod.reset(new HtspClientMethodDvrEntryAdd(*it));
        }
        else if (method == HTSP_METHOD_DVR_ENTRY_UPDATE)
        {
            clientMethod.reset(new HtspClientMethodDvrEntryUpdate(*it));
        }
        else if (method == HTSP_METHOD_INITIAL_SYNC_COMPLETED)
        {
            clientMethod.reset(new HtspClientMethodInitialSyncCompleted(*it));
        }
        else
        {
            stream << *it;
            throw std::runtime_error("invalid client method \"" + method + "\", content [" + stream.str() + "]");
        }

        if (clientMethod.get())
        {
            clientMethods.push_back(clientMethod);
        }

        it = messages.erase(it);
    }
}

std::string Htsp::getPackageInfo(void)
{
    return { PACKAGE_STRING };
}

int Htsp::getDefaultTcpPort(void)
{
    return HTSP_TCP_PORT_DEFAULT;
}

} /* namespace Flix */
