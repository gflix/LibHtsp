#ifndef HTSP_HTSPCLIENTMETHODDVRENTRYUPDATE_H_
#define HTSP_HTSPCLIENTMETHODDVRENTRYUPDATE_H_

#include <htsp/GenericHtspClientMethodDvrEntry.h>

namespace Flix {

class HtspClientMethodDvrEntryUpdate: public GenericHtspClientMethodDvrEntry {
public:
    HtspClientMethodDvrEntryUpdate(const HtspMessage& message);
    virtual ~HtspClientMethodDvrEntryUpdate();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODDVRENTRYUPDATE_H_ */
