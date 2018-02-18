#include <htsp/HtspClientMethodDvrEntryAdd.h>

namespace Flix {

HtspClientMethodDvrEntryAdd::HtspClientMethodDvrEntryAdd(const HtspMessage& message):
    GenericHtspClientMethodDvrEntry(HtspClientMethodType::DVR_ENTRY_ADD, message, HtspClientMethodAction::ADD)
{
}

HtspClientMethodDvrEntryAdd::~HtspClientMethodDvrEntryAdd()
{
}

} /* namespace Flix */
