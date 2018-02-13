#include <stdexcept>
#include <htsp/HtspMessageFieldSigned64.h>
#include <htsp/HtspMethodHello.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspMethodHelloRequest::HtspMethodHelloRequest(
    int htspVersion,
    const std::string& clientName,
    const std::string& clientVersion):
    htspVersion(htspVersion),
    clientName(clientName),
    clientVersion(clientVersion)
{
}

HtspMethodHelloResponse::HtspMethodHelloResponse(void):
    htspVersion(-1),
    apiVersion(-1)
{
}

HtspMethodHello::HtspMethodHello(const HtspMethodHelloRequest& request)
{
    requestMessage.appendString(HTSP_ID_METHOD, HTSP_METHOD_HELLO);
    requestMessage.appendSigned64(HTSP_ID_HTSP_VERSION, request.htspVersion);
    requestMessage.appendString(HTSP_ID_CLIENT_NAME, request.clientName);
    requestMessage.appendString(HTSP_ID_CLIENT_VERSION, request.clientVersion);
}

HtspMethodHello::~HtspMethodHello()
{
}

HtspMethodHelloResponse HtspMethodHello::getResponse(void) const
{
    if (responseMessages.empty())
    {
        throw std::length_error("empty response");
    }
    const HtspMessage& message = responseMessages.front();

    if (!message.hasField(HTSP_ID_HTSP_VERSION) ||
        !message.hasField(HTSP_ID_SERVER_NAME) ||
        !message.hasField(HTSP_ID_SERVER_VERSION) ||
        !message.hasField(HTSP_ID_CHALLENGE) ||
        !message.hasField(HTSP_ID_LANGUAGE) ||
        !message.hasField(HTSP_ID_SERVER_CAPABILITY) ||
        !message.hasField(HTSP_ID_API_VERSION))
    {
        throw std::out_of_range("invalid response");
    }

    HtspMethodHelloResponse response;

    response.htspVersion = message.getField(HTSP_ID_HTSP_VERSION)->toSigned64();
    response.serverName = message.getField(HTSP_ID_SERVER_NAME)->toString();
    response.serverVersion = message.getField(HTSP_ID_SERVER_VERSION)->toString();
    response.challenge = message.getField(HTSP_ID_CHALLENGE)->toString();
    response.language = message.getField(HTSP_ID_LANGUAGE)->toString();
    response.serverCapabilities = message.getField(HTSP_ID_SERVER_CAPABILITY)->toStringList();
    response.apiVersion = message.getField(HTSP_ID_API_VERSION)->toSigned64();

    return response;
}

} /* namespace Flix */
