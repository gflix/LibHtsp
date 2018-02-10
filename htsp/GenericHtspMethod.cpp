#include <htsp/GenericHtspMethod.h>

namespace Flix {

GenericHtspMethod::GenericHtspMethod()
{
}

GenericHtspMethod::~GenericHtspMethod()
{
}

const HtspMessage& GenericHtspMethod::getRequestMessage(void) const
{
    return requestMessage;
}

void GenericHtspMethod::setResponseMessages(const HtspMessages& messages)
{
    responseMessages = messages;
}

const HtspMessages& GenericHtspMethod::getResponseMessages(void) const
{
    return responseMessages;
}

} /* namespace Flix */
