#include <gtest/gtest.h>
#include "./sender.h"

class ReadingGeneratorTest : public ::testing::Test {
 protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    TEST_F(ReadingGeneratorTest, GenerateRandomReadings) {
    Sender generator;
    generator.generateAndSendReadings(100);
}
};
