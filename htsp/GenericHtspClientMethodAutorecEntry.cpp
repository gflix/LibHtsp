#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/GenericHtspClientMethodAutorecEntry.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspClientMethodAutorecEntryRequest::HtspClientMethodAutorecEntryRequest(void):
    enabled(false),
    daysOfWeek(0),
    priority(-1),
    channel(0)
{
}

GenericHtspClientMethodAutorecEntry::GenericHtspClientMethodAutorecEntry(
    HtspClientMethodType type,
    const HtspMessage& message,
    HtspClientMethodAction action):
    GenericHtspClientMethod(type),
    action(action)
{
    request.id = message.getField(HTSP_ID_ID)->toString();
    request.enabled = message.getField(HTSP_ID_ENABLED)->toSigned64() == 1;
    if (message.hasField(HTSP_ID_NAME))
        request.name = message.getField(HTSP_ID_NAME)->toString();
    request.daysOfWeek = message.getField(HTSP_ID_DAYS_OF_WEEK)->toSigned64() & 0x7f;
    request.priority = message.getField(HTSP_ID_PRIORITY)->toSigned64() & 0x07;
    if (message.hasField(HTSP_ID_TITLE))
        request.title = message.getField(HTSP_ID_TITLE)->toString();
    if (message.hasField(HTSP_ID_CHANNEL))
        request.channel = message.getField(HTSP_ID_CHANNEL)->toSigned64();
    if (message.hasField(HTSP_ID_OWNER))
        request.owner = message.getField(HTSP_ID_OWNER)->toString();
    if (message.hasField(HTSP_ID_CREATOR))
        request.creator = message.getField(HTSP_ID_CREATOR)->toString();
}

GenericHtspClientMethodAutorecEntry::~GenericHtspClientMethodAutorecEntry()
{
}

HtspClientMethodAction GenericHtspClientMethodAutorecEntry::getAction(void) const
{
    return action;
}

HtspClientMethodAutorecEntryRequest GenericHtspClientMethodAutorecEntry::getRequest(void) const
{
    return request;
}

std::string GenericHtspClientMethodAutorecEntry::dumpClientMethod(void) const
{
    std::stringstream stream;

    stream << "action=" << action << ", ";
    stream << "id=" << request.id << ", ";
    stream << "enabled=" << std::string(request.enabled ? "yes" : "no") << ", ";
    stream << "name=" << request.name << ", ";
    stream << "daysOfWeek=" << std::hex << request.daysOfWeek << std::dec << ", ";
    stream << "priority=" << request.priority << ", ";
    stream << "title=" << request.title << ", ";
    stream << "channel=" << request.channel << ", ";
    stream << "owner=" << request.owner << ", ";
    stream << "creator=" << request.creator;

    return stream.str();
}

} /* namespace Flix */
