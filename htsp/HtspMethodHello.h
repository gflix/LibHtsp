#ifndef HTSP_HTSPMETHODHELLO_H_
#define HTSP_HTSPMETHODHELLO_H_

#include <htsp/GenericHtspMethod.h>

namespace Flix {

struct HtspMethodHelloRequest
{
    HtspMethodHelloRequest(
        int htspVersion,
        const std::string& clientName,
        const std::string& clientVersion);

    int htspVersion;
    std::string clientName;
    std::string clientVersion;
};

typedef std::vector<std::string> ServerCapabilities;

struct HtspMethodHelloResponse
{
    HtspMethodHelloResponse(void);

    int htspVersion;
    std::string serverName;
    std::string serverVersion;
    std::string challenge;
    std::string language;
    ServerCapabilities serverCapabilities;
    int apiVersion;
};

class HtspMethodHello: public GenericHtspMethod {
public:
    HtspMethodHello(const HtspMethodHelloRequest& request);
    virtual ~HtspMethodHello();

    HtspMethodHelloResponse getResponse(void) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMETHODHELLO_H_ */
