#include "HtspMessageFieldSigned64.h"

namespace Flix {

HtspMessageFieldSigned64::HtspMessageFieldSigned64(int64_t value):
    GenericHtspMessageField(HtspMessageFieldType::SIGNED_64),
    value(value)
{
}

HtspMessageFieldSigned64::~HtspMessageFieldSigned64()
{
}

} /* namespace Flix */
