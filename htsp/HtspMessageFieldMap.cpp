#include <htsp/HtspMessage.h>
#include <htsp/HtspMessageFieldMap.h>

namespace Flix {

HtspMessageFieldMap::HtspMessageFieldMap(const std::string& identifier, const HtspMessage& value):
    GenericHtspMessageFieldArray(HtspMessageFieldType::MAP, identifier, value)
{
}

HtspMessageFieldMap::HtspMessageFieldMap(const std::string& identifier, const std::string& encodedValue):
    GenericHtspMessageFieldArray(HtspMessageFieldType::MAP, identifier, encodedValue)
{
}

HtspMessageFieldMap::~HtspMessageFieldMap()
{
}

} /* namespace Flix */
