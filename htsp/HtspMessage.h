#ifndef HTSP_HTSPMESSAGE_H_
#define HTSP_HTSPMESSAGE_H_

#include "GenericHtspMessageField.h"

namespace Flix {

class HtspMessage {
public:
    HtspMessage();
    virtual ~HtspMessage();

    void reset(void);

    void appendSigned64(int64_t value);
    void appendString(const std::string& value);

    size_t getFieldCount(void) const;

protected:
    HtspMessageFields fields;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGE_H_ */
