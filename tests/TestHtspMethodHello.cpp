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

TEST(HtspMethodHello, ResponseInvalid)
{
    Flix::HtspMethodHello request({4711, "test-client", "test-version"});

    Flix::HtspMessage responseMessage;
    request.setResponseMessages({responseMessage});

    Flix::HtspMethodHelloResponse response;
    EXPECT_ANY_THROW(response = request.getResponse());
}

TEST(HtspMethodHello, ResponseValid)
{
    Flix::HtspMethodHello request({4711, "test-client", "test-version"});

    Flix::HtspMessage responseMessage;
    responseMessage.appendSigned64(HTSP_ID_HTSP_VERSION, 99);
    responseMessage.appendString(HTSP_ID_SERVER_NAME, "dummy-server");
    responseMessage.appendString(HTSP_ID_SERVER_VERSION, "dummy-version");
    responseMessage.appendString(HTSP_ID_CHALLENGE, "01234567890123456789012345678901");
    responseMessage.appendString(HTSP_ID_LANGUAGE, "none");
    responseMessage.appendList(HTSP_ID_SERVER_CAPABILITY, Flix::HtspMessage());
    responseMessage.appendSigned64(HTSP_ID_API_VERSION, 66);
    request.setResponseMessages({responseMessage});

    Flix::HtspMethodHelloResponse response;
    EXPECT_NO_THROW(response = request.getResponse());
    EXPECT_EQ(response.htspVersion, 99);
    EXPECT_EQ(response.serverName, "dummy-server");
    EXPECT_EQ(response.serverVersion, "dummy-version");
    EXPECT_EQ(response.challenge, "01234567890123456789012345678901");
    EXPECT_EQ(response.language, "none");
    EXPECT_EQ(response.apiVersion, 66);
}
