#ifndef HTSP_GENERICHTSPCLIENTMETHODAUTORECENTRY_H_
#define HTSP_GENERICHTSPCLIENTMETHODAUTORECENTRY_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodAutorecEntryRequest {
    HtspClientMethodAutorecEntryRequest(void);

    std::string id;
    bool enabled;
    std::string name;
    int daysOfWeek;
    int priority;
    std::string title;
    unsigned int channel;
    std::string owner;
    std::string creator;
};

class GenericHtspClientMethodAutorecEntry: public GenericHtspClientMethod {
public:
    GenericHtspClientMethodAutorecEntry(
        HtspClientMethodType type,
        const HtspMessage& message,
        HtspClientMethodAction action);
    virtual ~GenericHtspClientMethodAutorecEntry();

    HtspClientMethodAction getAction(void) const;
    HtspClientMethodAutorecEntryRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

protected:
    HtspClientMethodAutorecEntryRequest request;

private:
    HtspClientMethodAction action;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHODAUTORECENTRY_H_ */
