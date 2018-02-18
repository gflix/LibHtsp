#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodTagAdd.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspClientMethodTagAddRequest::HtspClientMethodTagAddRequest(void):
    id(-1),
    sortingIndex(-1),
    titledIcon(false)
{
}

HtspClientMethodTagAdd::HtspClientMethodTagAdd(const HtspMessage& message):
    GenericHtspClientMethod(HtspClientMethodType::TAG_ADD)
{
    request.id = message.getField(HTSP_ID_TAG_ID)->toSigned64();
    request.name = message.getField(HTSP_ID_TAG_NAME)->toString();
    if (message.hasField(HTSP_ID_TAG_INDEX))
        request.sortingIndex = message.getField(HTSP_ID_TAG_INDEX)->toSigned64();
    if (message.hasField(HTSP_ID_TAG_ICON))
        request.icon = message.getField(HTSP_ID_TAG_ICON)->toString();
    if (message.hasField(HTSP_ID_TAG_TITLED_ICON))
        request.titledIcon = message.getField(HTSP_ID_TAG_TITLED_ICON)->toSigned64() == 1;
}

HtspClientMethodTagAdd::~HtspClientMethodTagAdd()
{
}

HtspClientMethodTagAddRequest HtspClientMethodTagAdd::getRequest(void) const
{
    return request;
}

std::string HtspClientMethodTagAdd::dumpClientMethod(void) const
{
    std::stringstream stream;

    stream << "id=" << request.id << ", ";
    stream << "name=" << request.name << ", ";
    stream << "sortingIndex=" << request.sortingIndex << ", ";
    stream << "icon=" << request.icon;

    return stream.str();
}

} /* namespace Flix */
