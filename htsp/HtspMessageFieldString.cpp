#include "HtspMessageFieldString.h"

namespace Flix {

HtspMessageFieldString::HtspMessageFieldString(const std::string& identifier, const std::string& value):
    GenericHtspMessageField(HtspMessageFieldType::STRING, identifier),
    value(value)
{
    encodedValue = value;
}

const std::string& HtspMessageFieldString::getValue(void) const
{
    return
        value;
}

HtspMessageFieldString::~HtspMessageFieldString()
{
}

} /* namespace Flix */
