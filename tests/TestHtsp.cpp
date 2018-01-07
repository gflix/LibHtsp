#include <gtest/gtest.h>
#include <htsp/Htsp.h>

TEST(Htsp, PackageInfo)
{
    EXPECT_EQ(Flix::Htsp::getPackageInfo(), "libhtsp 0.1");
}
