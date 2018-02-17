#include <stdexcept>
#include <networking/digest/Sha1.h>
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
        if (!request.password.empty() && !challenge.empty())
        {
            Sha1 sha1;

            sha1.appendMessage(request.password);
            sha1.appendMessage(challenge);

            std::string hash = sha1.getHash();

            requestMessage.appendBinary(HTSP_ID_DIGEST, hash);
        }
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

    HtspMethodAuthenticateResponse response;

    if (message.hasField(HTSP_ID_NO_ACCESS))
    {
        response.accessGranted = message.getField(HTSP_ID_NO_ACCESS)->toSigned64() != 1;
    }
    else
    {
        response.accessGranted = true;
    }

    return response;
}

} /* namespace Flix */
