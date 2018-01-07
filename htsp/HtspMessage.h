#ifndef HTSP_HTSPMESSAGE_H_
#define HTSP_HTSPMESSAGE_H_

#include <vector>
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
    GenericHtspMessageField* getField(const std::string& identifier) const;
    bool isFieldOfType(const std::string& identifier, HtspMessageFieldType type) const;

    std::string getEncoded(void) const;

    void setEncoded(std::string encoded);

protected:
    HtspMessageFields fields;

    void appendSigned64(const std::string& identifier, const std::string& encodedValue);
};

typedef std::vector<HtspMessage> HtspMessages;

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGE_H_ */
