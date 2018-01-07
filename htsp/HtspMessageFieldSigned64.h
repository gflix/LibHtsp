#ifndef HTSP_HTSPMESSAGEFIELDSIGNED64_H_
#define HTSP_HTSPMESSAGEFIELDSIGNED64_H_

#include "GenericHtspMessageField.h"

namespace Flix {

class HtspMessageFieldSigned64: public GenericHtspMessageField {
public:
    HtspMessageFieldSigned64(const std::string& identifier, int64_t value);
    HtspMessageFieldSigned64(const std::string& identifier, const std::string& encodedValue);
    virtual ~HtspMessageFieldSigned64();

    int64_t getValue(void) const;

private:
    int64_t value;

    void encodeValue(int64_t value);
    void decodeValue(const std::string& encodedValue);
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDSIGNED64_H_ */
