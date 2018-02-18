#ifndef HTSP_HTSPCLIENTMETHODTAGADD_H_
#define HTSP_HTSPCLIENTMETHODTAGADD_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

struct HtspClientMethodTagAddRequest {
    HtspClientMethodTagAddRequest(void);

    int id;
    std::string name;
    int sortingIndex;
    std::string icon;
    bool titledIcon;
};

class HtspClientMethodTagAdd: public GenericHtspClientMethod {
public:
    HtspClientMethodTagAdd(const HtspMessage& message);
    virtual ~HtspClientMethodTagAdd();

    HtspClientMethodTagAddRequest getRequest(void) const;

    virtual std::string dumpClientMethod(void) const;

private:
    HtspClientMethodTagAddRequest request;
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODTAGADD_H_ */
