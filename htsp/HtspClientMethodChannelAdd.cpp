#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodChannelAdd.h>

namespace Flix {

HtspClientMethodChannelAdd::HtspClientMethodChannelAdd(const HtspMessage& message):
    GenericHtspClientMethodChannel(HtspClientMethodType::CHANNEL_ADD, message, HtspClientMethodAction::ADD)
{
}

HtspClientMethodChannelAdd::~HtspClientMethodChannelAdd()
{
}

} /* namespace Flix */
