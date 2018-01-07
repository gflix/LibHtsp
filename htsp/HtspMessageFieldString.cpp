#include "HtspMessageFieldString.h"

namespace Flix {

HtspMessageFieldString::HtspMessageFieldString(const std::string& identifier, const std::string& value):
    GenericHtspMessageField(HtspMessageFieldType::STRING, identifier),
    value(value)
{
    encodedValue = value;
}

HtspMessageFieldString::~HtspMessageFieldString()
{
}

} /* namespace Flix */
