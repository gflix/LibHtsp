#include <sstream>
#include <htsp/HtspMessage.h>
#include <htsp/HtspClientMethodChannelAdd.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspClientMethodChannelAddRequest::HtspClientMethodChannelAddRequest(void):
    id(0),
    number(0),
    numberMinor(0)
{
}

HtspClientMethodChannelAdd::HtspClientMethodChannelAdd(const HtspMessage& message):
    GenericHtspClientMethod(HtspClientMethodType::CHANNEL_ADD)
{
    request.id = message.getField(HTSP_ID_CHANNEL_ID)->toSigned64();
    request.number = message.getField(HTSP_ID_CHANNEL_NUMBER)->toSigned64();
    if (message.hasField(HTSP_ID_CHANNEL_NUMBER_MINOR))
        request.numberMinor = message.getField(HTSP_ID_CHANNEL_NUMBER_MINOR)->toSigned64();
    request.name = message.getField(HTSP_ID_CHANNEL_NAME)->toString();
    if (message.hasField(HTSP_ID_CHANNEL_ICON))
        request.icon = message.getField(HTSP_ID_CHANNEL_ICON)->toString();
}

HtspClientMethodChannelAdd::~HtspClientMethodChannelAdd()
{
}

HtspClientMethodChannelAddRequest HtspClientMethodChannelAdd::getRequest(void) const
{
    return request;
}

std::string HtspClientMethodChannelAdd::dumpClientMethod(void) const
{
    std::stringstream stream;

    stream << "id=" << request.id << ", ";
    stream << "number=" << request.number << "." << request.numberMinor << ", ";
    stream << "name=" << request.name << ", ";
    stream << "icon=" << request.icon;

    return stream.str();
}

} /* namespace Flix */
