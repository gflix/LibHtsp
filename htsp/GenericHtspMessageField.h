#ifndef HTSP_GENERICHTSPMESSAGEFIELD_H_
#define HTSP_GENERICHTSPMESSAGEFIELD_H_

#include <memory>
#include <vector>

namespace Flix {

enum class HtspMessageFieldType {
    UNKNOWN = 0,
    SIGNED_64 = 2,
    STRING = 3
};

class GenericHtspMessageField {
public:
    GenericHtspMessageField(HtspMessageFieldType type);
    virtual ~GenericHtspMessageField();

protected:
    HtspMessageFieldType type;
};

typedef std::shared_ptr<GenericHtspMessageField> HtspMessageField;
typedef std::vector<HtspMessageField> HtspMessageFields;

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMESSAGEFIELD_H_ */
