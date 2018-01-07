#include "HtspMessageFieldSigned64.h"

namespace Flix {

HtspMessageFieldSigned64::HtspMessageFieldSigned64(const std::string& identifier, int64_t value):
    GenericHtspMessageField(HtspMessageFieldType::SIGNED_64, identifier),
    value(value)
{
    encodeValue(value);
}

HtspMessageFieldSigned64::~HtspMessageFieldSigned64()
{
}

void HtspMessageFieldSigned64::encodeValue(int64_t value)
{
    encodedValue.clear();

    for (int i = 0; i < 8; ++i)
    {
        encodedValue += static_cast<unsigned char>(value & 0xff);
        value >>= 8;

        if (value == 0)
        {
            break;
        }
    }
}

} /* namespace Flix */
