#ifndef HTSP_HTSPMESSAGEFIELDLIST_H_
#define HTSP_HTSPMESSAGEFIELDLIST_H_

#include <htsp/GenericHtspMessageField.h>

namespace Flix {

class HtspMessage;

class HtspMessageFieldList: public GenericHtspMessageField {
public:
    HtspMessageFieldList(const std::string& identifier, const HtspMessage& value);
    HtspMessageFieldList(const std::string& identifier, const std::string& encodedValue);
    virtual ~HtspMessageFieldList();

    const HtspMessage& getValue(void) const;

    virtual std::string dumpValue(void) const override;

private:
    HtspMessage value;
};

} /* namespace Flix */

#endif /* HTSP_HTSPMESSAGEFIELDLIST_H_ */
