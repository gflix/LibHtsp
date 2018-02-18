#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodTagUpdate.h>

namespace Flix {

HtspClientMethodTagUpdate::HtspClientMethodTagUpdate(const HtspMessage& message):
    GenericHtspClientMethodTag(HtspClientMethodType::TAG_UPDATE, message, HtspClientMethodAction::UPDATE)
{
}

HtspClientMethodTagUpdate::~HtspClientMethodTagUpdate()
{
}

} /* namespace Flix */
