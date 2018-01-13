#include "HtspMessageFieldString.h"

namespace Flix {

HtspMessageFieldString::HtspMessageFieldString(const std::string& identifier, const std::string& value):
    GenericHtspMessageFieldBlob(HtspMessageFieldType::STRING, identifier, value)
{
}

HtspMessageFieldString::~HtspMessageFieldString()
{
}

std::string HtspMessageFieldString::dumpValue(void) const
{
    return
        value;
}

} /* namespace Flix */
