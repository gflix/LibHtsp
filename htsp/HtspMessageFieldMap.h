#ifndef HTSP_HTSPMESSAGEFIELDMAP_H_
#define HTSP_HTSPMESSAGEFIELDMAP_H_

#include <htsp/GenericHtspMessageFieldArray.h>

namespace Flix {

class HtspMessageFieldMap: public GenericHtspMessageFieldArray {
public:
    HtspMessageFieldMap(const std::string& identifier, const HtspMessage& value);
    HtspMessageFieldMap(const std::string& identifier, const std::string& encodedValue);
    virtual ~HtspMessageFieldMap();
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDMAP_H_ */
