#ifndef HTSP_HTSPCLIENTMETHODTAGADD_H_
#define HTSP_HTSPCLIENTMETHODTAGADD_H_

#include <htsp/GenericHtspClientMethodTag.h>

namespace Flix {

class HtspMessage;

class HtspClientMethodTagAdd: public GenericHtspClientMethodTag {
public:
    HtspClientMethodTagAdd(const HtspMessage& message);
    virtual ~HtspClientMethodTagAdd();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODTAGADD_H_ */
