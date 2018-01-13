#include "GenericHtspMessageFieldBlob.h"

namespace Flix {

GenericHtspMessageFieldBlob::GenericHtspMessageFieldBlob(
    HtspMessageFieldType type,
    const std::string& identifier,
    const std::string& value):
    GenericHtspMessageField(type, identifier),
    value(value)
{
    encodedValue = value;
}

GenericHtspMessageFieldBlob::~GenericHtspMessageFieldBlob()
{
}

const std::string& GenericHtspMessageFieldBlob::getValue(void) const
{
    return
        value;
}

} /* namespace Flix */
