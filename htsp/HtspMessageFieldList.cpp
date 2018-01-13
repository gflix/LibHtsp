#include <sstream>
#include "HtspMessage.h"
#include "HtspMessageFieldList.h"

namespace Flix {

HtspMessageFieldList::HtspMessageFieldList(const std::string& identifier, const HtspMessage& value):
    GenericHtspMessageField(HtspMessageFieldType::LIST, identifier),
    value(value)
{
    encodedValue = value.getEncoded();
}

HtspMessageFieldList::HtspMessageFieldList(const std::string& identifier, const std::string& encodedValue):
    GenericHtspMessageField(HtspMessageFieldType::LIST, identifier)
{
    this->encodedValue = encodedValue;
    value.setEncoded(encodedValue);
}


HtspMessageFieldList::~HtspMessageFieldList()
{
}

const HtspMessage& HtspMessageFieldList::getValue(void) const
{
    return
        value;
}

std::string HtspMessageFieldList::dumpValue(void) const
{
    std::stringstream stream;

    stream << value;
    return
        stream.str();
}

} /* namespace Flix */
