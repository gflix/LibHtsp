#include "HtspMessageFieldString.h"

namespace Flix {

HtspMessageFieldString::HtspMessageFieldString(const std::string& value):
    GenericHtspMessageField(HtspMessageFieldType::STRING),
    value(value)
{
}

HtspMessageFieldString::~HtspMessageFieldString()
{
}

} /* namespace Flix */
