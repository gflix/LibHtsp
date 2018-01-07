#include "Autoconf.h"
#include "Htsp.h"

#ifndef PACKAGE_STRING
#define PACKAGE_STRING "unknown"
#endif

namespace Flix {

std::string Htsp::getPackageInfo(void)
{
    return { PACKAGE_STRING };
}

} /* namespace Flix */
