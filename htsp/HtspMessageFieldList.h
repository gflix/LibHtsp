#ifndef HTSP_HTSPMESSAGEFIELDLIST_H_
#define HTSP_HTSPMESSAGEFIELDLIST_H_

#include <htsp/GenericHtspMessageFieldArray.h>

namespace Flix {

class HtspMessageFieldList: public GenericHtspMessageFieldArray {
public:
    HtspMessageFieldList(const std::string& identifier, const HtspMessage& value);
    HtspMessageFieldList(const std::string& identifier, const std::string& encodedValue);
    virtual ~HtspMessageFieldList();
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDLIST_H_ */
