#ifndef HTSP_HTSPCLIENTMETHODCHANNELADD_H_
#define HTSP_HTSPCLIENTMETHODCHANNELADD_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodChannelAddRequest {
    HtspClientMethodChannelAddRequest(void);

    unsigned int id;
    unsigned int number;
    unsigned int numberMinor;
    std::string name;
    std::string icon;
};

class HtspClientMethodChannelAdd: public GenericHtspClientMethod {
public:
    HtspClientMethodChannelAdd(const HtspMessage& message);
    virtual ~HtspClientMethodChannelAdd();

    HtspClientMethodChannelAddRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

private:
    HtspClientMethodChannelAddRequest request;
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODCHANNELADD_H_ */
