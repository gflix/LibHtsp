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

void HtspMessage::appendSigned64(const std::string& identifier, int64_t value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldSigned64(identifier, value)));
}

void HtspMessage::appendString(const std::string& identifier, const std::string& value)
{
    fields.push_back(HtspMessageField(new HtspMessageFieldString(identifier, value)));
}

size_t HtspMessage::getFieldCount(void) const
{
    return
        fields.size();
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

void HtspMessage::decode(std::string encoded)
{
    reset();

    while (!encoded.empty())
    {
        throw std::string("not yet implemented");
    }
}

} /* namespace Flix */
