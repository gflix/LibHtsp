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
        throw std::string("empty response");
    }
    const HtspMessage& message = responseMessages.front();

    if (!message.hasField(HTSP_ID_HTSP_VERSION) ||
        !message.hasField(HTSP_ID_SERVER_NAME) ||
        !message.hasField(HTSP_ID_SERVER_VERSION))
    {
        throw std::string("invalid response");
    }

    HtspMethodHelloResponse response;

    response.htspVersion = message.getField(HTSP_ID_HTSP_VERSION)->toSigned64();
    response.serverName = message.getField(HTSP_ID_SERVER_NAME)->toString();
    response.serverVersion = message.getField(HTSP_ID_SERVER_VERSION)->toString();

    return response;
}

} /* namespace Flix */