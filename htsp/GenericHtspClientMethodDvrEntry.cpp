#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/GenericHtspClientMethodDvrEntry.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspClientMethodDvrEntryRequest::HtspClientMethodDvrEntryRequest(void):
    id(0),
    channel(0),
    start(0),
    stop(0),
    startExtra(0),
    stopExtra(0),
    priority(-1),
    enabled(true)
{
}

GenericHtspClientMethodDvrEntry::GenericHtspClientMethodDvrEntry(
    HtspClientMethodType type,
    const HtspMessage& message,
    HtspClientMethodAction action):
    GenericHtspClientMethod(type),
    action(action)
{
    request.id = message.getField(HTSP_ID_ID)->toSigned64();
    if (message.hasField(HTSP_ID_CHANNEL))
        request.channel = message.getField(HTSP_ID_CHANNEL)->toSigned64();
    request.start = message.getField(HTSP_ID_START)->toSigned64();
    request.startExtra = message.getField(HTSP_ID_START_EXTRA)->toSigned64();
    request.stop = message.getField(HTSP_ID_STOP)->toSigned64();
    request.stopExtra = message.getField(HTSP_ID_STOP_EXTRA)->toSigned64();
    request.priority = message.getField(HTSP_ID_PRIORITY)->toSigned64() & 0x07;
    if (message.hasField(HTSP_ID_TITLE))
        request.title = message.getField(HTSP_ID_TITLE)->toString();
    if (message.hasField(HTSP_ID_SUBTITLE))
        request.subtitle = message.getField(HTSP_ID_SUBTITLE)->toString();
    if (message.hasField(HTSP_ID_OWNER))
        request.owner = message.getField(HTSP_ID_OWNER)->toString();
    if (message.hasField(HTSP_ID_CREATOR))
        request.creator = message.getField(HTSP_ID_CREATOR)->toString();
    if (message.hasField(HTSP_ID_ENABLED))
        request.enabled = message.getField(HTSP_ID_ENABLED)->toSigned64() == 1;
}

GenericHtspClientMethodDvrEntry::~GenericHtspClientMethodDvrEntry()
{
}

HtspClientMethodAction GenericHtspClientMethodDvrEntry::getAction(void) const
{
    return action;
}

HtspClientMethodDvrEntryRequest GenericHtspClientMethodDvrEntry::getRequest(void) const
{
    return request;
}

std::string GenericHtspClientMethodDvrEntry::dumpClientMethod(void) const
{
    std::stringstream stream;

    stream << "action=" << action << ", ";
    stream << "id=" << request.id << ", ";
    stream << "channel=" << request.channel << ", ";
    stream << "start=" << request.start << " (+" << request.startExtra << "min), ";
    stream << "stop=" << request.stop << " (+" << request.stopExtra << "min), ";
    stream << "priority=" << request.priority << ", ";
    stream << "title=" << request.title << ", ";
    stream << "subtitle=" << request.subtitle << ", ";
    stream << "owner=" << request.owner << ", ";
    stream << "creator=" << request.creator << ", ";
    stream << "enabled=" << std::string(request.enabled ? "yes" : "no");

    return stream.str();
}

} /* namespace Flix */
