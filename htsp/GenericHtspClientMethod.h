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
    TAG_UPDATE,
    CHANNEL_ADD,
    AUTOREC_ENTRY_ADD,
    DVR_ENTRY_ADD,
    DVR_ENTRY_UPDATE,
    INITIAL_SYNC_COMPLETED,
};

enum class HtspClientMethodAction {
    UNKNOWN,
    ADD,
    UPDATE,
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
std::ostream& operator<<(std::ostream& stream, HtspClientMethodAction action);

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPCLIENTMETHOD_H_ */
