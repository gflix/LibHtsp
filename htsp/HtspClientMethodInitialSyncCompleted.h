#ifndef HTSP_HTSPCLIENTMETHODINITIALSYNCCOMPLETED_H_
#define HTSP_HTSPCLIENTMETHODINITIALSYNCCOMPLETED_H_

#include <htsp/GenericHtspClientMethod.h>

namespace Flix {

class HtspMessage;

class HtspClientMethodInitialSyncCompleted: public GenericHtspClientMethod {
public:
    HtspClientMethodInitialSyncCompleted(const HtspMessage& message);
    virtual ~HtspClientMethodInitialSyncCompleted();

    virtual std::string dumpClientMethod(void) const;
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODINITIALSYNCCOMPLETED_H_ */
