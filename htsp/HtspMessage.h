#ifndef HTSP_HTSPMESSAGE_H_
#define HTSP_HTSPMESSAGE_H_

#include "GenericHtspMessageField.h"

namespace Flix {

class HtspMessage {
public:
    HtspMessage();
    virtual ~HtspMessage();

    void reset(void);

    void appendSigned64(const std::string& identifier, int64_t value);
    void appendString(const std::string& identifier, const std::string& value);

    size_t getFieldCount(void) const;
    bool hasField(const std::string& identifier) const;

    std::string getEncoded(void) const;

protected:
    HtspMessageFields fields;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGE_H_ */
