#ifndef HTSP_HTSPCLIENTMETHODTAGUPDATE_H_
#define HTSP_HTSPCLIENTMETHODTAGUPDATE_H_

#include <htsp/GenericHtspClientMethodTag.h>

namespace Flix {

class HtspMessage;

class HtspClientMethodTagUpdate: public GenericHtspClientMethodTag {
public:
    HtspClientMethodTagUpdate(const HtspMessage& message);
    virtual ~HtspClientMethodTagUpdate();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODTAGUPDATE_H_ */
