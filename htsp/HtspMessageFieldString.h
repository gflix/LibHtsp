#ifndef HTSP_HTSPMESSAGEFIELDSTRING_H_
#define HTSP_HTSPMESSAGEFIELDSTRING_H_

#include <string>
#include "GenericHtspMessageField.h"

namespace Flix {

class HtspMessageFieldString: public GenericHtspMessageField {
public:
    HtspMessageFieldString(const std::string& identifier, const std::string& value);
    virtual ~HtspMessageFieldString();

    const std::string& getValue(void) const;

private:
    std::string value;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDSTRING_H_ */
