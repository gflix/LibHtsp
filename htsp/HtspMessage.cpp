#include "HtspMessage.h"
#include "HtspMessageFieldBinary.h"
#include "HtspMessageFieldList.h"
#include "HtspMessageFieldSigned64.h"
#include "HtspMessageFieldString.h"

#if HTSP_MESSAGE_DUMP_ENCODED
    #include <iostream>
    #include <sstream>
#endif

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

void HtspMessage::appendSigned64(const std::string& identifier, int64_t value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldSigned64(identifier, value)));
}

void HtspMessage::appendString(const std::string& identifier, const std::string& value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldString(identifier, value)));
}

void HtspMessage::appendBinary(const std::string& identifier, const std::string& value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldBinary(identifier, value)));
}

void HtspMessage::appendList(const std::string& identifier, const HtspMessage& value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldList(identifier, value)));
}

size_t HtspMessage::getFieldCount(void) const
{
    return
        fields.size();
}

const HtspMessageFields& HtspMessage::getFields(void) const
{
    return
        fields;
}

bool HtspMessage::hasField(const std::string& identifier) const
{
    if (identifier.empty())
    {
        return false;
    }

    for (auto& wrappedField: fields)
    {
        GenericHtspMessageField* field = wrappedField.get();
        if (!field || field->getType() == HtspMessageFieldType::UNKNOWN)
        {
            continue;
        }
        if (field->getIdentifier() == identifier)
        {
            return true;
        }
    }
    return false;
}

const HtspMessageField& HtspMessage::getField(const std::string& identifier) const
{
    if (!hasField(identifier))
    {
        throw std::string("field " + identifier + " not found");
    }

    for (auto& field: fields)
    {
        if (field->getIdentifier() == identifier)
        {
            return field;
        }
    }
    throw std::string("field " + identifier + " not found");
}

bool HtspMessage::isFieldOfType(const std::string& identifier, HtspMessageFieldType type) const
{
    HtspMessageField field = getField(identifier);

    return
        field &&
        field->getType() == type;
}

std::string HtspMessage::getEncoded(void) const
{
    std::string encodedSize;
    std::string encodedFields;

    for (auto& wrappedField: fields)
    {
        GenericHtspMessageField* field = wrappedField.get();
        if (!field || field->getType() == HtspMessageFieldType::UNKNOWN)
        {
            continue;
        }
        encodedFields += field->getEncoded();
    }

    size_t encodedFieldsSize = encodedFields.size();
    encodedSize += static_cast<unsigned char>((encodedFieldsSize >> 24) & 0xff);
    encodedSize += static_cast<unsigned char>((encodedFieldsSize >> 16) & 0xff);
    encodedSize += static_cast<unsigned char>((encodedFieldsSize >> 8) & 0xff);
    encodedSize += static_cast<unsigned char>(encodedFieldsSize & 0xff);

    return
        encodedSize + encodedFields;
}

void HtspMessage::setEncoded(std::string encoded)
{
    reset();

    while (!encoded.empty())
    {
        // Minimum 6 bytes: type, length of identifier and length of data
        size_t encodedSize = encoded.size();
        if (encodedSize < 6)
        {
            throw std::string("too few bytes left in buffer");
        }

        HtspMessageFieldType type = static_cast<HtspMessageFieldType>(encoded[0]);
        unsigned char identifierSize = static_cast<unsigned char>(encoded[1]);
        size_t dataSize = 0;
        for (int i = 0; i < 4; ++i)
        {
            dataSize = (dataSize << 8) | static_cast<unsigned char>(encoded[i + 2]);
        }

        encoded.erase(0, 6);

        // process identifier and data of the message
        encodedSize = encoded.size();
        if (encodedSize < identifierSize + dataSize)
        {
            throw std::string("too few bytes left in buffer");
        }

        std::string identifier { encoded.substr(0, identifierSize) };
        encoded.erase(0, identifierSize);
        std::string rawValue { encoded.substr(0, dataSize) };
        encoded.erase(0, dataSize);

        switch (type)
        {
        case HtspMessageFieldType::SIGNED_64:
            appendSigned64(identifier, rawValue);
            break;
        case HtspMessageFieldType::STRING:
            appendString(identifier, rawValue);
            break;
        case HtspMessageFieldType::BINARY:
            appendBinary(identifier, rawValue);
            break;
        case HtspMessageFieldType::LIST:
            appendList(identifier, rawValue);
            break;
        default:
#if HTSP_MESSAGE_DUMP_ENCODED
            dumpEncoded(rawValue);
#endif
            throw std::string("invalid or not supported message field type " + std::to_string(static_cast<int>(type)) + " for identifier " + identifier);
            break;
        }
    }
}

void HtspMessage::appendSigned64(const std::string& identifier, const std::string& encodedValue)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldSigned64(identifier, encodedValue)));
}

void HtspMessage::appendList(const std::string& identifier, const std::string& encodedValue)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldList(identifier, encodedValue)));
}

#if HTSP_MESSAGE_DUMP_ENCODED
void HtspMessage::dumpEncoded(const std::string& encoded) const
{
    std::stringstream dump;

    dump << std::hex;
    dump << "[";

    for (auto& character: encoded)
    {
        dump << "0x" << static_cast<int>(character) << " ";

        if (character >= 32 && character < 127)
        {
            dump << "(" << character << ") ";
        }
    }

    dump << "]";

    std::cout << dump.str() << std::endl;
}
#endif

std::ostream& operator<<(std::ostream& stream, const HtspMessage& message)
{
    stream << "HtspMessage[";
    bool firstField = true;
    for (auto& field: message.getFields())
    {
        if (firstField)
        {
            firstField = false;
        }
        else
        {
            stream << ", ";
        }
        stream << *field.get();
    }
    stream << "]";

    return stream;
}

} /* namespace Flix */
