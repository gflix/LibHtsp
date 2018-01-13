#include <gtest/gtest.h>
#include <htsp/HtspMessage.h>
#include <htsp/HtspMessageFieldSigned64.h>
#include <htsp/HtspMessageFieldString.h>

TEST(HtspMessage, FieldCount)
{
    Flix::HtspMessage htspMessage;
    std::string dummyIdentifierA { "A" };
    std::string dummyIdentifierB { "B" };
    int dummyInt = 0;
    std::string dummyString { "dummy" };

    EXPECT_EQ(htspMessage.getFieldCount(), 0);

    htspMessage.appendSigned64(dummyIdentifierA, dummyInt);
    EXPECT_EQ(htspMessage.getFieldCount(), 1);

    htspMessage.appendString(dummyIdentifierB, dummyString);
    EXPECT_EQ(htspMessage.getFieldCount(), 2);

    htspMessage.reset();
    EXPECT_EQ(htspMessage.getFieldCount(), 0);
}

TEST(HtspMessage, Fields)
{
    Flix::HtspMessage htspMessage;
    std::string dummyIdentifierA { "A" };
    std::string dummyIdentifierB { "B" };
    int dummyInt = 0;
    std::string dummyString { "dummy" };

    EXPECT_FALSE(htspMessage.hasField(dummyIdentifierA));
    EXPECT_FALSE(htspMessage.hasField(dummyIdentifierB));

    htspMessage.appendSigned64(dummyIdentifierA, dummyInt);
    EXPECT_TRUE(htspMessage.hasField(dummyIdentifierA));
    EXPECT_FALSE(htspMessage.hasField(dummyIdentifierB));

    htspMessage.appendString(dummyIdentifierB, dummyString);
    EXPECT_TRUE(htspMessage.hasField(dummyIdentifierA));
    EXPECT_TRUE(htspMessage.hasField(dummyIdentifierB));

    htspMessage.reset();
    EXPECT_FALSE(htspMessage.hasField(dummyIdentifierA));
    EXPECT_FALSE(htspMessage.hasField(dummyIdentifierB));
}

TEST(HtspMessage, FieldSigned64)
{
    std::string dummyIdentifierA { "A" };
    int64_t dummyIntA = 0;
    Flix::HtspMessageFieldSigned64 htspMessageFieldA(dummyIdentifierA, dummyIntA);

    std::string dummyIdentifierB { "B" };
    int64_t dummyIntB = 256;
    Flix::HtspMessageFieldSigned64 htspMessageFieldB(dummyIdentifierB, dummyIntB);

    std::string dummyIdentifierC { "C" };
    int64_t dummyIntC = 65536;
    Flix::HtspMessageFieldSigned64 htspMessageFieldC(dummyIdentifierC, dummyIntC);

    std::string dummyIdentifierD { "D" };
    int64_t dummyIntD = 16777216;
    Flix::HtspMessageFieldSigned64 htspMessageFieldD(dummyIdentifierD, dummyIntD);

    std::string dummyIdentifierE { "E" };
    int64_t dummyIntE = 4294967296;
    Flix::HtspMessageFieldSigned64 htspMessageFieldE(dummyIdentifierE, dummyIntE);

    std::string dummyIdentifierF { "F" };
    int64_t dummyIntF = 1099511627776;
    Flix::HtspMessageFieldSigned64 htspMessageFieldF(dummyIdentifierF, dummyIntF);

    std::string dummyIdentifierG { "G" };
    int64_t dummyIntG = -1;
    Flix::HtspMessageFieldSigned64 htspMessageFieldG(dummyIdentifierG, dummyIntG);

    std::string encodedA = htspMessageFieldA.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(1)
    EXPECT_EQ(encodedA.size(), 8);

    std::string encodedB = htspMessageFieldB.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(2)
    EXPECT_EQ(encodedB.size(), 9);

    std::string encodedC = htspMessageFieldC.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(3)
    EXPECT_EQ(encodedC.size(), 10);

    std::string encodedD = htspMessageFieldD.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(4)
    EXPECT_EQ(encodedD.size(), 11);

    std::string encodedE = htspMessageFieldE.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(5)
    EXPECT_EQ(encodedE.size(), 12);

    std::string encodedF = htspMessageFieldF.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(6)
    EXPECT_EQ(encodedF.size(), 13);

    std::string encodedG = htspMessageFieldG.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(8)
    EXPECT_EQ(encodedG.size(), 15);
}

TEST(HtspMessage, FieldString)
{
    std::string dummyIdentifierA { "A" };
    std::string dummyStringA;
    Flix::HtspMessageFieldString htspMessageFieldA(dummyIdentifierA, dummyStringA);

    std::string dummyIdentifierB { "B" };
    std::string dummyStringB { "dummy" };
    Flix::HtspMessageFieldString htspMessageFieldB(dummyIdentifierB, dummyStringB);

    std::string dummyIdentifierC { "idC" };
    std::string dummyStringC { "dummy" };
    Flix::HtspMessageFieldString htspMessageFieldC(dummyIdentifierC, dummyStringC);

    std::string encodedA = htspMessageFieldA.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(0)
    EXPECT_EQ(encodedA.size(), 7);

    std::string encodedB = htspMessageFieldB.getEncoded();
    // type(1), name_length(1), data_length(4), name(1), data(5)
    EXPECT_EQ(encodedB.size(), 12);

    std::string encodedC = htspMessageFieldC.getEncoded();
    // type(1), name_length(1), data_length(4), name(3), data(5)
    EXPECT_EQ(encodedC.size(), 14);
}

TEST(HtspMessage, Encode)
{
    Flix::HtspMessage htspMessageA;
    std::string expectedEncodedA { "\x00\x00\x00\x00", 4 };

    std::string dummyIdentifierB { "B" };
    std::string dummyStringB { "dummy" };
    Flix::HtspMessage htspMessageB;
    htspMessageB.appendString(dummyIdentifierB, dummyStringB);

    std::string dummyIdentifierC1 { "C1" };
    std::string dummyStringC1 { "dummy" };
    std::string dummyIdentifierC2 { "C2" };
    int dummyIntC2 = 255;
    Flix::HtspMessage htspMessageC;
    htspMessageC.appendString(dummyIdentifierC1, dummyStringC1);
    htspMessageC.appendSigned64(dummyIdentifierC2, dummyIntC2);

    std::string encodedA = htspMessageA.getEncoded();
    // length(4)
    EXPECT_EQ(encodedA.size(), 4);
    EXPECT_EQ(encodedA, expectedEncodedA);

    std::string encodedB = htspMessageB.getEncoded();
    // length(4), string(12)
    EXPECT_EQ(encodedB.size(), 16);

    std::string encodedC = htspMessageC.getEncoded();
    // length(4), string(13), signed64(9)
    EXPECT_EQ(encodedC.size(), 26);
}

TEST(HtspMessage, Decode)
{
    Flix::HtspMessage htspMessage;
    std::string encodedA;
    std::string encodedB { "\x02\x01\x00\x00\x00\x01I\xff", 8 };
    std::string encodedC { "\x03\x01\x00\x00\x00\x05Idummy", 12 };
    std::string encodedD { "\x02\x01\x00\x00\x00\x01I\xff\x03\x01\x00\x00\x00\x05Kdummy", 20 };
    std::string encodedE { "\x00\x00\x00\x00\x00\x00", 6 };

    EXPECT_NO_THROW(htspMessage.setEncoded(encodedA));

    EXPECT_NO_THROW(htspMessage.setEncoded(encodedB));
    EXPECT_EQ(htspMessage.getFieldCount(), 1);
    EXPECT_TRUE(htspMessage.hasField("I"));
    EXPECT_TRUE(htspMessage.isFieldOfType("I", Flix::HtspMessageFieldType::SIGNED_64));
    Flix::HtspMessageFieldSigned64* htspMessageFieldB;
    EXPECT_NO_THROW(htspMessageFieldB = static_cast<Flix::HtspMessageFieldSigned64*>(htspMessage.getField("I").get()));
    EXPECT_EQ(htspMessageFieldB->getValue(), 255);

    EXPECT_NO_THROW(htspMessage.setEncoded(encodedC));
    EXPECT_EQ(htspMessage.getFieldCount(), 1);
    EXPECT_TRUE(htspMessage.hasField("I"));
    EXPECT_TRUE(htspMessage.isFieldOfType("I", Flix::HtspMessageFieldType::STRING));
    Flix::HtspMessageFieldString* htspMessageFieldC;
    EXPECT_NO_THROW(htspMessageFieldC = static_cast<Flix::HtspMessageFieldString*>(htspMessage.getField("I").get()));
    EXPECT_EQ(htspMessageFieldC->getValue(), "dummy");

    EXPECT_NO_THROW(htspMessage.setEncoded(encodedD));
    EXPECT_EQ(htspMessage.getFieldCount(), 2);
    EXPECT_TRUE(htspMessage.hasField("I"));
    EXPECT_TRUE(htspMessage.hasField("K"));
    EXPECT_TRUE(htspMessage.isFieldOfType("I", Flix::HtspMessageFieldType::SIGNED_64));
    EXPECT_TRUE(htspMessage.isFieldOfType("K", Flix::HtspMessageFieldType::STRING));
    Flix::HtspMessageFieldSigned64* htspMessageFieldD1;
    Flix::HtspMessageFieldString* htspMessageFieldD2;
    EXPECT_NO_THROW(htspMessageFieldD1 = static_cast<Flix::HtspMessageFieldSigned64*>(htspMessage.getField("I").get()));
    EXPECT_NO_THROW(htspMessageFieldD2 = static_cast<Flix::HtspMessageFieldString*>(htspMessage.getField("K").get()));
    EXPECT_EQ(htspMessageFieldD1->getValue(), 255);
    EXPECT_EQ(htspMessageFieldD2->getValue(), "dummy");

    EXPECT_ANY_THROW(htspMessage.setEncoded(encodedE));
}
