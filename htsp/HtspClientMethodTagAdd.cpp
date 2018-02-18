#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodTagAdd.h>

namespace Flix {

HtspClientMethodTagAdd::HtspClientMethodTagAdd(const HtspMessage& message):
    GenericHtspClientMethod(HtspClientMethodType::TAG_ADD)
{
}

HtspClientMethodTagAdd::~HtspClientMethodTagAdd()
{
}

std::string HtspClientMethodTagAdd::dumpClientMethod(void) const
{
    return "not yet implemented";
}

} /* namespace Flix */
