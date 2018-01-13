#include <gtest/gtest.h>
#include <htsp/Htsp.h>
#include <htsp/HtspMessageFieldSigned64.h>
#include <htsp/HtspMessageFieldString.h>

TEST(Htsp, PackageInfo)
{
    EXPECT_EQ(Flix::Htsp::getPackageInfo(), "libhtsp 0.1.0");
}

TEST(Htsp, Defaults)
{
    Flix::Htsp htsp;

    EXPECT_FALSE(htsp.isConnected());
    EXPECT_FALSE(htsp.hasMessage());
}

TEST(Htsp, DecodeMessages)
{
    Flix::Htsp htsp;
    std::string encodedA { "\x00\x00\x00\x08", 4 };
    std::string encodedB { "\x02\x01\x00\x00\x00\x01I\xff", 8 };
    std::string encodedC { "\x00\x00\x00\x0c\x03\x01\x00\x00\x00\x05Idummy", 16 };

    EXPECT_FALSE(htsp.hasMessage());
    htsp.appendReceivedData(encodedA);
    EXPECT_FALSE(htsp.hasMessage());
    htsp.appendReceivedData(encodedB);
    EXPECT_TRUE(htsp.hasMessage());
    htsp.appendReceivedData(encodedC);

    Flix::HtspMessages htspMessages;
    EXPECT_NO_THROW(htsp.getMessages(htspMessages));
    EXPECT_EQ(htspMessages.size(), 2);

    Flix::HtspMessage htspMessage = htspMessages[0];
    EXPECT_EQ(htspMessage.getFieldCount(), 1);
    EXPECT_TRUE(htspMessage.hasField("I"));
    EXPECT_TRUE(htspMessage.isFieldOfType("I", Flix::HtspMessageFieldType::SIGNED_64));

    Flix::HtspMessageFieldSigned64* htspMessageSigned64;
    EXPECT_NO_THROW(htspMessageSigned64 = static_cast<Flix::HtspMessageFieldSigned64*>(htspMessage.getField("I").get()));
    EXPECT_EQ(htspMessageSigned64->getValue(), 255);

    EXPECT_EQ(htspMessage.getEncoded(), encodedA + encodedB);

    htspMessage = htspMessages[1];
    EXPECT_EQ(htspMessage.getFieldCount(), 1);
    EXPECT_TRUE(htspMessage.hasField("I"));
    EXPECT_TRUE(htspMessage.isFieldOfType("I", Flix::HtspMessageFieldType::STRING));

    Flix::HtspMessageFieldString* htspMessageString;
    EXPECT_NO_THROW(htspMessageString = static_cast<Flix::HtspMessageFieldString*>(htspMessage.getField("I").get()));
    EXPECT_EQ(htspMessageString->getValue(), "dummy");

    EXPECT_EQ(htspMessage.getEncoded(), encodedC);

    EXPECT_FALSE(htsp.hasMessage());
}
