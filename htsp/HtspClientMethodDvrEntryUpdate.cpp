#include <htsp/HtspClientMethodDvrEntryUpdate.h>

namespace Flix {

HtspClientMethodDvrEntryUpdate::HtspClientMethodDvrEntryUpdate(const HtspMessage& message):
    GenericHtspClientMethodDvrEntry(HtspClientMethodType::DVR_ENTRY_UPDATE, message, HtspClientMethodAction::UPDATE)
{
}

HtspClientMethodDvrEntryUpdate::~HtspClientMethodDvrEntryUpdate()
{
}

} /* namespace Flix */
