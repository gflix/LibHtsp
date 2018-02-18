#ifndef HTSP_HTSPCLIENTMETHODDVRENTRYADD_H_
#define HTSP_HTSPCLIENTMETHODDVRENTRYADD_H_

#include <htsp/GenericHtspClientMethodDvrEntry.h>

namespace Flix {

class HtspClientMethodDvrEntryAdd: public GenericHtspClientMethodDvrEntry {
public:
    HtspClientMethodDvrEntryAdd(const HtspMessage& message);
    virtual ~HtspClientMethodDvrEntryAdd();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODDVRENTRYADD_H_ */
