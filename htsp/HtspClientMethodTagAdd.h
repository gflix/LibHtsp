#ifndef HTSP_HTSPCLIENTMETHODTAGADD_H_
#define HTSP_HTSPCLIENTMETHODTAGADD_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

class HtspClientMethodTagAdd: public GenericHtspClientMethod {
public:
    HtspClientMethodTagAdd(const HtspMessage& message);
    virtual ~HtspClientMethodTagAdd();

    virtual std::string dumpClientMethod(void) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODTAGADD_H_ */
