#ifndef HTSP_GENERICHTSPCLIENTMETHODCHANNEL_H_
#define HTSP_GENERICHTSPCLIENTMETHODCHANNEL_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodChannelRequest {
    HtspClientMethodChannelRequest(void);

    unsigned int id;
    unsigned int number;
    unsigned int numberMinor;
    std::string name;
    std::string icon;
};

class GenericHtspClientMethodChannel: public GenericHtspClientMethod {
public:
    GenericHtspClientMethodChannel(
        HtspClientMethodType type,
        const HtspMessage& message,
        HtspClientMethodAction action);
    virtual ~GenericHtspClientMethodChannel();

    HtspClientMethodAction getAction(void) const;
    HtspClientMethodChannelRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

private:
    HtspClientMethodChannelRequest request;

private:
    HtspClientMethodAction action;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHODCHANNEL_H_ */
