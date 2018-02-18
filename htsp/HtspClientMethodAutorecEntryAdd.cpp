#include <htsp/HtspClientMethodAutorecEntryAdd.h>

namespace Flix {

HtspClientMethodAutorecEntryAdd::HtspClientMethodAutorecEntryAdd(const HtspMessage& message):
    GenericHtspClientMethodAutorecEntry(HtspClientMethodType::AUTOREC_ENTRY_ADD, message, HtspClientMethodAction::ADD)
{
}

HtspClientMethodAutorecEntryAdd::~HtspClientMethodAutorecEntryAdd()
{
}

} /* namespace Flix */
