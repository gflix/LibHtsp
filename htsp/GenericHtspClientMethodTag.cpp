#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/GenericHtspClientMethodTag.h>
#include <htsp/HtspTags.h>

namespace Flix {


HtspClientMethodTagRequest::HtspClientMethodTagRequest(void):
    id(-1),
    sortingIndex(-1),
    titledIcon(false)
{
}

GenericHtspClientMethodTag::GenericHtspClientMethodTag(
    HtspClientMethodType type,
    const HtspMessage& message,
    HtspClientMethodAction action):
    GenericHtspClientMethod(type),
    action(action)
{
    request.id = message.getField(HTSP_ID_TAG_ID)->toSigned64();
    if (action == HtspClientMethodAction::ADD || message.hasField(HTSP_ID_TAG_NAME))
        request.name = message.getField(HTSP_ID_TAG_NAME)->toString();
    if (message.hasField(HTSP_ID_TAG_INDEX))
        request.sortingIndex = message.getField(HTSP_ID_TAG_INDEX)->toSigned64();
    if (message.hasField(HTSP_ID_TAG_ICON))
        request.icon = message.getField(HTSP_ID_TAG_ICON)->toString();
    if (message.hasField(HTSP_ID_TAG_TITLED_ICON))
        request.titledIcon = message.getField(HTSP_ID_TAG_TITLED_ICON)->toSigned64() == 1;
}

GenericHtspClientMethodTag::~GenericHtspClientMethodTag()
{
}

HtspClientMethodAction GenericHtspClientMethodTag::getAction(void) const
{
    return action;
}

HtspClientMethodTagRequest GenericHtspClientMethodTag::getRequest(void) const
{
    return request;
}

std::string GenericHtspClientMethodTag::dumpClientMethod(void) const
{
    std::stringstream stream;

    stream << "action=" << action << ", ";
    stream << "id=" << request.id << ", ";
    stream << "name=" << request.name << ", ";
    stream << "sortingIndex=" << request.sortingIndex << ", ";
    stream << "icon=" << request.icon;

    return stream.str();
}

} /* namespace Flix */
