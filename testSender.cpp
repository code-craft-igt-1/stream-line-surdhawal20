#include <gtest/gtest.h>
#include "./sender.h"

class SenderTest : public ::testing::Test {
 protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    TEST_F(SenderTest, GenerateRandomReadings) {
    Sender generator;
    generator.generateAndSendReadings(100);
}
};
