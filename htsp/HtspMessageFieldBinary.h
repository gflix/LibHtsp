#ifndef HTSP_HTSPMESSAGEFIELDBINARY_H_
#define HTSP_HTSPMESSAGEFIELDBINARY_H_

#include "GenericHtspMessageFieldBlob.h"

namespace Flix {

class HtspMessageFieldBinary: public GenericHtspMessageFieldBlob {
public:
    HtspMessageFieldBinary(const std::string& identifier, const std::string& value);
    virtual ~HtspMessageFieldBinary();

    virtual std::string dumpValue(void) const override;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDBINARY_H_ */
