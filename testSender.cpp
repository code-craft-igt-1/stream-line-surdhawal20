#include <gtest/gtest.h>
#include "./sender.h"

class SenderTest : public ::testing::Test {
 protected:
    Sender sender;
};

TEST_F(SenderTest, GenerateRandomReadings) {
    sender.generateAndSendReadings(100);
}

TEST_F(SenderTest, OutputFormattingConsole) {
    testing::internal::CaptureStdout();
    sender.generateAndSendReadings(1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_ANY_THROW(output, ::testing::Contains("Temperature:"));
    EXPECT_ANY_THROW(output, ::testing::Contains("Pulse Rate:"));
    EXPECT_ANY_THROW(output, ::testing::Contains("SPO2:"));
}
