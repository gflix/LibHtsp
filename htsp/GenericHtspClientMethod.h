#ifndef HTSP_GENERICHTSPCLIENTMETHOD_H_
#define HTSP_GENERICHTSPCLIENTMETHOD_H_

#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace Flix {

enum class HtspClientMethodType {
    UNKNOWN,
    TAG_ADD,
    CHANNEL_ADD
};

class GenericHtspClientMethod {
public:
    GenericHtspClientMethod(HtspClientMethodType type);
    virtual ~GenericHtspClientMethod();

    HtspClientMethodType getType(void) const;
    virtual std::string dumpClientMethod(void) const = 0;

protected:
    HtspClientMethodType type;
};

typedef std::shared_ptr<GenericHtspClientMethod> HtspClientMethod;
typedef std::vector<HtspClientMethod> HtspClientMethods;

std::ostream& operator<<(std::ostream& stream, const GenericHtspClientMethod& method);
std::ostream& operator<<(std::ostream& stream, HtspClientMethodType type);

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHOD_H_ */