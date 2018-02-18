#ifndef HTSP_GENERICHTSPCLIENTMETHODTAG_H_
#define HTSP_GENERICHTSPCLIENTMETHODTAG_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodTagRequest {
    HtspClientMethodTagRequest(void);

    int id;
    std::string name;
    int sortingIndex;
    std::string icon;
    bool titledIcon;
};

class GenericHtspClientMethodTag: public GenericHtspClientMethod {
public:
    GenericHtspClientMethodTag(
        HtspClientMethodType type,
        const HtspMessage& message,
        HtspClientMethodAction action);
    virtual ~GenericHtspClientMethodTag();

    HtspClientMethodAction getAction(void) const;
    HtspClientMethodTagRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

protected:
    HtspClientMethodTagRequest request;

private:
    HtspClientMethodAction action;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHODTAG_H_ */
