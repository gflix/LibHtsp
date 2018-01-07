#include "HtspMessage.h"
#include "HtspMessageFieldSigned64.h"
#include "HtspMessageFieldString.h"

namespace Flix {

HtspMessage::HtspMessage()
{
}

HtspMessage::~HtspMessage()
{
}

void HtspMessage::reset(void)
{
    fields.clear();
}

void HtspMessage::appendSigned64(int64_t value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldSigned64(value)));
}

void HtspMessage::appendString(const std::string& value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldString(value)));
}

size_t HtspMessage::getFieldCount(void) const
{
    return
        fields.size();
}

} /* namespace Flix */
