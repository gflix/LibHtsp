#include <stdexcept>
#include <htsp/HtspMethodAuthenticate.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspMethodAuthenticateRequest::HtspMethodAuthenticateRequest(
    const std::string& username,
    const std::string& password):
    username(username),
    password(password)
{
}

HtspMethodAuthenticateResponse::HtspMethodAuthenticateResponse(void):
    accessGranted(false)
{
}

HtspMethodAuthenticate::HtspMethodAuthenticate(
    const HtspMethodAuthenticateRequest& request,
    const std::string& challenge)
{
    requestMessage.appendString(HTSP_ID_METHOD, HTSP_METHOD_AUTHENTICATE);
    if (!request.username.empty())
    {
        requestMessage.appendString(HTSP_ID_USERNAME, request.username);
    }
}

HtspMethodAuthenticate::~HtspMethodAuthenticate()
{
}

HtspMethodAuthenticateResponse HtspMethodAuthenticate::getResponse(void) const
{
    if (responseMessages.empty())
    {
        throw std::length_error("empty response");
    }

    const HtspMessage& message = responseMessages.front();

    if (!message.hasField(HTSP_ID_NO_ACCESS))
    {
        throw std::out_of_range("invalid response");
    }

    HtspMethodAuthenticateResponse response;

    response.accessGranted = message.getField(HTSP_ID_NO_ACCESS)->toSigned64() != 1;

    return response;
}

} /* namespace Flix */
