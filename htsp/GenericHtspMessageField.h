#ifndef HTSP_GENERICHTSPMESSAGEFIELD_H_
#define HTSP_GENERICHTSPMESSAGEFIELD_H_

#include <memory>
#include <string>
#include <vector>

namespace Flix {

enum class HtspMessageFieldType {
    UNKNOWN = 0,
    SIGNED_64 = 2,
    STRING = 3
};

class GenericHtspMessageField {
public:
    GenericHtspMessageField(HtspMessageFieldType type, const std::string& identifier);
    virtual ~GenericHtspMessageField();

    HtspMessageFieldType getType(void) const;
    const std::string& getIdentifier(void) const;

    std::string getEncoded(void) const;

protected:
    HtspMessageFieldType type;
    std::string identifier;
    std::string encodedValue;
};

typedef std::shared_ptr<GenericHtspMessageField> HtspMessageField;
typedef std::vector<HtspMessageField> HtspMessageFields;

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMESSAGEFIELD_H_ */
