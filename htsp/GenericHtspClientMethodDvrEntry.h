#ifndef HTSP_GENERICHTSPCLIENTMETHODDVRENTRY_H_
#define HTSP_GENERICHTSPCLIENTMETHODDVRENTRY_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodDvrEntryRequest {
    HtspClientMethodDvrEntryRequest(void);

    unsigned int id;
    unsigned int channel;
    int64_t start;
    int64_t stop;
    int priority;
    std::string title;
    std::string subtitle;
    std::string owner;
    std::string creator;
    bool enabled;
};

class GenericHtspClientMethodDvrEntry: public GenericHtspClientMethod {
public:
    GenericHtspClientMethodDvrEntry(
        HtspClientMethodType type,
        const HtspMessage& message,
        HtspClientMethodAction action);
    virtual ~GenericHtspClientMethodDvrEntry();

    HtspClientMethodAction getAction(void) const;
    HtspClientMethodDvrEntryRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

protected:
    HtspClientMethodDvrEntryRequest request;

private:
    HtspClientMethodAction action;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHODDVRENTRY_H_ */
