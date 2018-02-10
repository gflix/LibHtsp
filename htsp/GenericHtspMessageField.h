#ifndef HTSP_GENERICHTSPMESSAGEFIELD_H_
#define HTSP_GENERICHTSPMESSAGEFIELD_H_

#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace Flix {

enum class HtspMessageFieldType {
    UNKNOWN = 0,
    SIGNED_64 = 2,
    STRING = 3,
    BINARY = 4,
    LIST = 5,
};

class GenericHtspMessageField {
public:
    GenericHtspMessageField(HtspMessageFieldType type, const std::string& identifier);
    virtual ~GenericHtspMessageField();

    HtspMessageFieldType getType(void) const;
    const std::string& getIdentifier(void) const;
    bool hasIdentifier(void) const;

    std::string getEncoded(void) const;

    virtual std::string dumpValue(void) const = 0;

    int64_t toSigned64(void) const;
    const std::string& toString(void) const;

protected:
    HtspMessageFieldType type;
    std::string identifier;
    std::string encodedValue;
};

typedef std::shared_ptr<GenericHtspMessageField> HtspMessageField;
typedef std::vector<HtspMessageField> HtspMessageFields;

std::ostream& operator<<(std::ostream& stream, const GenericHtspMessageField& field);
std::ostream& operator<<(std::ostream& stream, HtspMessageFieldType fieldType);

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMESSAGEFIELD_H_ */
