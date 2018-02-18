#include <cassert>
#include <stdexcept>
#include <htsp/HtspMessage.h>
#include <htsp/GenericHtspMessageField.h>
#include <htsp/GenericHtspMessageFieldBlob.h>
#include <htsp/HtspMessageFieldList.h>
#include <htsp/HtspMessageFieldSigned64.h>

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

bool GenericHtspMessageField::hasIdentifier(void) const
{
    return
        !identifier.empty();
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

int64_t GenericHtspMessageField::toSigned64(void) const
{
    if (type != HtspMessageFieldType::SIGNED_64)
    {
        throw std::invalid_argument("invalid field type");
    }

    return
        dynamic_cast<const HtspMessageFieldSigned64*>(this)->getValue();
}

const std::string& GenericHtspMessageField::toString(void) const
{
    if (type != HtspMessageFieldType::STRING &&
        type != HtspMessageFieldType::BINARY)
    {
        throw std::invalid_argument("invalid field type");
    }

    return
        dynamic_cast<const GenericHtspMessageFieldBlob*>(this)->getValue();
}

std::vector<std::string> GenericHtspMessageField::toStringList(void) const
{
    if (type != HtspMessageFieldType::LIST)
    {
        throw std::invalid_argument("invalid field type");
    }

    std::vector<std::string> stringList;
    for (auto& field: dynamic_cast<const HtspMessageFieldList*>(this)->getValue().getFields())
    {
        stringList.push_back(field->toString());
    }

    return stringList;
}

std::ostream& operator<<(std::ostream& stream, const GenericHtspMessageField& field)
{
    if (field.hasIdentifier())
    {
        stream << field.getIdentifier() << "=";
    }

    stream << field.getType() << "(" << field.dumpValue() << ")";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, HtspMessageFieldType fieldType)
{
    switch (fieldType)
    {
    case HtspMessageFieldType::MAP:
        stream << "map";
        break;
    case HtspMessageFieldType::SIGNED_64:
        stream << "signed64";
        break;
    case HtspMessageFieldType::STRING:
        stream << "string";
        break;
    case HtspMessageFieldType::BINARY:
        stream << "binary";
        break;
    case HtspMessageFieldType::LIST:
        stream << "list";
        break;
    default:
        stream << "unknown";
    }

    return stream;
}

} /* namespace Flix */
