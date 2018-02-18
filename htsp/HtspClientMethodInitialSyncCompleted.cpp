#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodInitialSyncCompleted.h>

namespace Flix {

HtspClientMethodInitialSyncCompleted::HtspClientMethodInitialSyncCompleted(const HtspMessage& message):
    GenericHtspClientMethod(HtspClientMethodType::INITIAL_SYNC_COMPLETED)
{
}

HtspClientMethodInitialSyncCompleted::~HtspClientMethodInitialSyncCompleted()
{
}

std::string HtspClientMethodInitialSyncCompleted::dumpClientMethod(void) const
{
    return std::string();
}

} /* namespace Flix */
