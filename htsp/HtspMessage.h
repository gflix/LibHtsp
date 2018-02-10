#ifndef HTSP_HTSPMESSAGE_H_
#define HTSP_HTSPMESSAGE_H_

#include <ostream>
#include <vector>
#include <htsp/GenericHtspMessageField.h>

#define HTSP_MESSAGE_DUMP_ENCODED (1)

namespace Flix {

class HtspMessage {
public:
    HtspMessage();
    virtual ~HtspMessage();

    void reset(void);

    void appendSigned64(const std::string& identifier, int64_t value);
    void appendString(const std::string& identifier, const std::string& value);
    void appendBinary(const std::string& identifier, const std::string& value);
    void appendList(const std::string& identifier, const HtspMessage& value);

    size_t getFieldCount(void) const;
    const HtspMessageFields& getFields(void) const;
    bool hasField(const std::string& identifier) const;
    const HtspMessageField& getField(const std::string& identifier) const;
    bool isFieldOfType(const std::string& identifier, HtspMessageFieldType type) const;

    std::string getEncoded(void) const;

    void setEncoded(std::string encoded);

protected:
    HtspMessageFields fields;

    void appendSigned64(const std::string& identifier, const std::string& encodedValue);
    void appendList(const std::string& identifier, const std::string& encodedValue);
#if HTSP_MESSAGE_DUMP_ENCODED
    void dumpEncoded(const std::string& encoded) const;
#endif
};

typedef std::vector<HtspMessage> HtspMessages;

std::ostream& operator<<(std::ostream& stream, const HtspMessage& message);

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGE_H_ */
