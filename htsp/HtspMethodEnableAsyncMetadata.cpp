#include <htsp/HtspMethodEnableAsyncMetadata.h>
#include <htsp/HtspTags.h>

namespace Flix {

HtspMethodEnableAsyncMetadataRequest::HtspMethodEnableAsyncMetadataRequest(
    bool includeEpg):
    includeEpg(includeEpg)
{
}

HtspMethodEnableAsyncMetadata::HtspMethodEnableAsyncMetadata(
    const HtspMethodEnableAsyncMetadataRequest& request)
{
    requestMessage.appendString(HTSP_ID_METHOD, HTSP_METHOD_ENABLE_ASYNC_METADATA);
    requestMessage.appendSigned64(HTSP_ID_EPG, request.includeEpg ? 1 : 0);
}

HtspMethodEnableAsyncMetadata::~HtspMethodEnableAsyncMetadata()
{
}

} /* namespace Flix */
