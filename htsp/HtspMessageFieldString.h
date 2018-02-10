#ifndef HTSP_HTSPMESSAGEFIELDSTRING_H_
#define HTSP_HTSPMESSAGEFIELDSTRING_H_

#include <htsp/GenericHtspMessageFieldBlob.h>

namespace Flix {

class HtspMessageFieldString: public GenericHtspMessageFieldBlob {
public:
    HtspMessageFieldString(const std::string& identifier, const std::string& value);
    virtual ~HtspMessageFieldString();

    virtual std::string dumpValue(void) const override;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDSTRING_H_ */
