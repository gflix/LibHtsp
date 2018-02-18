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
    default:
        stream << "unknown";
    }

    return stream;
}

} /* namespace Flix */
