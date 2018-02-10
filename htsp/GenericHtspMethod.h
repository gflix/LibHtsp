#ifndef HTSP_GENERICHTSPMETHOD_H_
#define HTSP_GENERICHTSPMETHOD_H_

#include <htsp/HtspMessage.h>

namespace Flix {

class GenericHtspMethod {
public:
    GenericHtspMethod();
    virtual ~GenericHtspMethod();

    const HtspMessage& getRequestMessage(void) const;
    void setResponseMessages(const HtspMessages& messages);
    const HtspMessages& getResponseMessages(void) const;

protected:
    HtspMessage requestMessage;
    HtspMessages responseMessages;
};

} /* namespace Flix */

#endif /* HTSP_GENERICHTSPMETHOD_H_ */
