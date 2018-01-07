#include <cassert>
#include "GenericHtspMessageField.h"

#define IDENTIFIER_MAX_LENGTH (255)

namespace Flix {

GenericHtspMessageField::GenericHtspMessageField(HtspMessageFieldType type, const std::string& identifier):
    type(type),
    identifier(identifier)
{
    assert(identifier.size() <= IDENTIFIER_MAX_LENGTH);
}

GenericHtspMessageField::~GenericHtspMessageField()
{
}

HtspMessageFieldType GenericHtspMessageField::getType(void) const
{
    return
        type;
}

const std::string& GenericHtspMessageField::getIdentifier(void) const
{
    return
        identifier;
}

std::string GenericHtspMessageField::getEncoded(void) const
{
    std::string encoded;

    encoded += static_cast<unsigned char>(type);
    encoded += static_cast<unsigned char>(identifier.size());

    size_t dataSize = encodedValue.size();
    encoded += static_cast<unsigned char>((dataSize >> 24) & 0xff);
    encoded += static_cast<unsigned char>((dataSize >> 16) & 0xff);
    encoded += static_cast<unsigned char>((dataSize >> 8) & 0xff);
    encoded += static_cast<unsigned char>(dataSize & 0xff);

    encoded += identifier;
    encoded += encodedValue;

    return encoded;
}

} /* namespace Flix */
