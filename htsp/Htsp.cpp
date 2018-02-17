#include <htsp/Autoconf.h>
#include <stdexcept>
#include <networking/Select.h>
#include <htsp/Htsp.h>

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

    Select select;
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

std::string Htsp::getPackageInfo(void)
{
    return { PACKAGE_STRING };
}

int Htsp::getDefaultTcpPort(void)
{
    return HTSP_TCP_PORT_DEFAULT;
}

} /* namespace Flix */
