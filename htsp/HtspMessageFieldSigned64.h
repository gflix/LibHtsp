#ifndef HTSP_HTSPMESSAGEFIELDSIGNED64_H_
#define HTSP_HTSPMESSAGEFIELDSIGNED64_H_

#include "GenericHtspMessageField.h"

namespace Flix {

class HtspMessageFieldSigned64: public GenericHtspMessageField {
public:
    HtspMessageFieldSigned64(int64_t value);
    virtual ~HtspMessageFieldSigned64();

private:
    int64_t value;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDSIGNED64_H_ */
