#ifndef HTSP_GENERICHTSPMESSAGEFIELDBLOB_H_
#define HTSP_GENERICHTSPMESSAGEFIELDBLOB_H_

#include <string>
#include "GenericHtspMessageField.h"

namespace Flix {

class GenericHtspMessageFieldBlob: public GenericHtspMessageField {
public:
    GenericHtspMessageFieldBlob(
        HtspMessageFieldType type,
        const std::string& identifier,
        const std::string& value);
    virtual ~GenericHtspMessageFieldBlob();

    const std::string& getValue(void) const;

protected:
    std::string value;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMESSAGEFIELDBLOB_H_ */
