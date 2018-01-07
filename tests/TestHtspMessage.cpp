#include <gtest/gtest.h>
#include <htsp/HtspMessage.h>

TEST(HtspMessage, FieldCount)
{
    Flix::HtspMessage htspMessage;
    std::string dummyString { "dummy" };

    EXPECT_EQ(htspMessage.getFieldCount(), 0);

    htspMessage.appendSigned64(0);
    EXPECT_EQ(htspMessage.getFieldCount(), 1);

    htspMessage.appendString(dummyString);
    EXPECT_EQ(htspMessage.getFieldCount(), 2);

    htspMessage.reset();
    EXPECT_EQ(htspMessage.getFieldCount(), 0);
}
