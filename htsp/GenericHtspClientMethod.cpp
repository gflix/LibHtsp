#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

GenericHtspClientMethod::GenericHtspClientMethod(HtspClientMethodType type):
    type(type)
{
}

GenericHtspClientMethod::~GenericHtspClientMethod()
{
}

HtspClientMethodType GenericHtspClientMethod::getType(void) const
{
    return type;
}

std::ostream& operator<<(std::ostream& stream, const GenericHtspClientMethod& method)
{
    stream << method.getType() << "(" << method.dumpClientMethod() << ")";

    return stream;
}

std::ostream& operator<<(std::ostream& stream, HtspClientMethodType type)
{
    switch (type)
    {
    case HtspClientMethodType::TAG_ADD:
        stream << "tagAdd";
        break;
    case HtspClientMethodType::CHANNEL_ADD:
        stream << "channelAdd";
        break;
    default:
        stream << "unknown";
    }

    return stream;
}

std::ostream& operator<<(std::ostream& stream, HtspClientMethodAction action)
{
    switch (action)
    {
    case HtspClientMethodAction::ADD:
        stream << "add";
        break;
    case HtspClientMethodAction::UPDATE:
        stream << "update";
        break;
    default:
        stream << "unknown";
    }

    return stream;
}

} /* namespace Flix */
