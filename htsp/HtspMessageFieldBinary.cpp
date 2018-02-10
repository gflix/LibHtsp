#include <htsp/HtspMessageFieldBinary.h>

namespace Flix {

HtspMessageFieldBinary::HtspMessageFieldBinary(const std::string& identifier, const std::string& value):
    GenericHtspMessageFieldBlob(HtspMessageFieldType::BINARY, identifier, value)
{
}

HtspMessageFieldBinary::~HtspMessageFieldBinary()
{
}

std::string HtspMessageFieldBinary::dumpValue(void) const
{
    return
        std::to_string(value.size());
}

} /* namespace Flix */
