#ifndef HTSP_HTSPCLIENTMETHODAUTORECENTRYADD_H_
#define HTSP_HTSPCLIENTMETHODAUTORECENTRYADD_H_

#include <htsp/GenericHtspClientMethodAutorecEntry.h>

namespace Flix {

class HtspClientMethodAutorecEntryAdd: public GenericHtspClientMethodAutorecEntry {
public:
    HtspClientMethodAutorecEntryAdd(const HtspMessage& message);
    virtual ~HtspClientMethodAutorecEntryAdd();
};

} /* namespace Flix */

#endif /* HTSP_HTSPCLIENTMETHODAUTORECENTRYADD_H_ */
