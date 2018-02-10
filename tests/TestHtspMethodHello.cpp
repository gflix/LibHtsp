#include <gtest/gtest.h>
#include <htsp/HtspMethodHello.h>
#include <htsp/HtspTags.h>

TEST(HtspMethodHello, Request)
{
    Flix::HtspMethodHello request({4711, "test-client", "test-version"});
    Flix::HtspMessage requestMessage = request.getRequestMessage();

    EXPECT_TRUE(requestMessage.hasField(HTSP_ID_METHOD));
    EXPECT_TRUE(requestMessage.hasField(HTSP_ID_HTSP_VERSION));
    EXPECT_TRUE(requestMessage.hasField(HTSP_ID_CLIENT_NAME));
    EXPECT_TRUE(requestMessage.hasField(HTSP_ID_CLIENT_VERSION));
}
