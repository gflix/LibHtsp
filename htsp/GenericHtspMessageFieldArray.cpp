#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/GenericHtspMessageFieldArray.h>

namespace Flix {

GenericHtspMessageFieldArray::GenericHtspMessageFieldArray(
    HtspMessageFieldType type,
    const std::string& identifier,
    const HtspMessage& value):
    GenericHtspMessageField(type, identifier),
    value(value)
{
    encodedValue = value.getEncoded();
}

GenericHtspMessageFieldArray::GenericHtspMessageFieldArray(
    HtspMessageFieldType type,
    const std::string& identifier,
    const std::string& encodedValue):
    GenericHtspMessageField(type, identifier)
{
    this->encodedValue = encodedValue;
    value.setEncoded(encodedValue);
}


GenericHtspMessageFieldArray::~GenericHtspMessageFieldArray()
{
}

const HtspMessage& GenericHtspMessageFieldArray::getValue(void) const
{
    return
        value;
}

std::string GenericHtspMessageFieldArray::dumpValue(void) const
{
    std::stringstream stream;

    stream << value;
    return
        stream.str();
}

} /* namespace Flix */
