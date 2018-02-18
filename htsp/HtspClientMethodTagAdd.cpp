#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodTagAdd.h>

namespace Flix {

HtspClientMethodTagAdd::HtspClientMethodTagAdd(const HtspMessage& message):
    GenericHtspClientMethodTag(HtspClientMethodType::TAG_ADD, message, HtspClientMethodAction::ADD)
{
}

HtspClientMethodTagAdd::~HtspClientMethodTagAdd()
{
}

} /* namespace Flix */
