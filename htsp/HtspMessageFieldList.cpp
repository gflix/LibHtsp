#include <htsp/HtspMessage.h>
#include <htsp/HtspMessageFieldList.h>

namespace Flix {

HtspMessageFieldList::HtspMessageFieldList(const std::string& identifier, const HtspMessage& value):
    GenericHtspMessageFieldArray(HtspMessageFieldType::LIST, identifier, value)
{
}

HtspMessageFieldList::HtspMessageFieldList(const std::string& identifier, const std::string& encodedValue):
    GenericHtspMessageFieldArray(HtspMessageFieldType::LIST, identifier, encodedValue)
{
}

HtspMessageFieldList::~HtspMessageFieldList()
{
}

} /* namespace Flix */
