#ifndef HTSP_HTSPCLIENTMETHODCHANNELADD_H_
#define HTSP_HTSPCLIENTMETHODCHANNELADD_H_

#include <htsp/GenericHtspClientMethodChannel.h>

namespace Flix {

class HtspClientMethodChannelAdd: public GenericHtspClientMethodChannel {
public:
    HtspClientMethodChannelAdd(const HtspMessage& message);
    virtual ~HtspClientMethodChannelAdd();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODCHANNELADD_H_ */
