#ifndef HTSP_HTSPMETHODAUTHENTICATE_H_
#define HTSP_HTSPMETHODAUTHENTICATE_H_

#include <htsp/GenericHtspMethod.h>

namespace Flix {

struct HtspMethodAuthenticateRequest
{
    HtspMethodAuthenticateRequest(
        const std::string& username,
        const std::string& password);

    std::string username;
    std::string password;
};

struct HtspMethodAuthenticateResponse
{
    HtspMethodAuthenticateResponse(void);

    bool accessGranted;
};

class HtspMethodAuthenticate: public GenericHtspMethod {
public:
    HtspMethodAuthenticate(const HtspMethodAuthenticateRequest& request, const std::string& challenge);
    virtual ~HtspMethodAuthenticate();

    HtspMethodAuthenticateResponse getResponse(void) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMETHODAUTHENTICATE_H_ */
