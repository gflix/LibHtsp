#ifndef HTSP_HTSPMETHODENABLEASYNCMETADATA_H_
#define HTSP_HTSPMETHODENABLEASYNCMETADATA_H_

#include <htsp/GenericHtspMethod.h>

namespace Flix {

struct HtspMethodEnableAsyncMetadataRequest
{
    HtspMethodEnableAsyncMetadataRequest(
        bool includeEpg);

    bool includeEpg;
};

class HtspMethodEnableAsyncMetadata: public GenericHtspMethod {
public:
    HtspMethodEnableAsyncMetadata(const HtspMethodEnableAsyncMetadataRequest& request);
    virtual ~HtspMethodEnableAsyncMetadata();
};

} /* namespace Flix */

#endif /* HTSP_HTSPMETHODENABLEASYNCMETADATA_H_ */
