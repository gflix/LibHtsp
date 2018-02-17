#ifndef HTSP_GENERICHTSPMESSAGEFIELDARRAY_H_
#define HTSP_GENERICHTSPMESSAGEFIELDARRAY_H_

#include <htsp/GenericHtspMessageField.h>

namespace Flix {

class HtspMessage;

class GenericHtspMessageFieldArray: public GenericHtspMessageField {
public:
    GenericHtspMessageFieldArray(
        HtspMessageFieldType type,
        const std::string& identifier,
        const HtspMessage& value);
    GenericHtspMessageFieldArray(
        HtspMessageFieldType type,
        const std::string& identifier,
        const std::string& encodedValue);
    virtual ~GenericHtspMessageFieldArray();

    const HtspMessage& getValue(void) const;

    virtual std::string dumpValue(void) const override;

private:
    HtspMessage value;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMESSAGEFIELDARRAY_H_ */
