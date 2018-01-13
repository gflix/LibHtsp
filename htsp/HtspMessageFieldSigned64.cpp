#include "HtspMessageFieldSigned64.h"

namespace Flix {

HtspMessageFieldSigned64::HtspMessageFieldSigned64(const std::string& identifier, int64_t value):
    GenericHtspMessageField(HtspMessageFieldType::SIGNED_64, identifier),
    value(value)
{
    encodeValue(value);
}

HtspMessageFieldSigned64::HtspMessageFieldSigned64(const std::string& identifier, const std::string& encodedValue):
    GenericHtspMessageField(HtspMessageFieldType::SIGNED_64, identifier)
{
    this->encodedValue = encodedValue;
    decodeValue(encodedValue);
}


HtspMessageFieldSigned64::~HtspMessageFieldSigned64()
{
}

int64_t HtspMessageFieldSigned64::getValue(void) const
{
    return
        value;
}

std::string HtspMessageFieldSigned64::dumpValue(void) const
{
    return
        std::to_string(value);
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

void HtspMessageFieldSigned64::decodeValue(const std::string& encodedValue)
{
    value = 0;

    if (encodedValue.size() > 8)
    {
        throw std::string("invalid input for signed64 value");
    }

    for (auto character: encodedValue)
    {
        value = (value << 8) | static_cast<unsigned char>(character);
    }
}

} /* namespace Flix */
