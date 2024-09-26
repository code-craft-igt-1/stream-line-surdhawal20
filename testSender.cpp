#include <gtest/gtest.h>
#include "./reading_generator.h"

class ReadingGeneratorTest : public ::testing::Test {
 protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

    TEST_F(ReadingGeneratorTest, GenerateRandomReadings) {
    ReadingGenerator generator;
    generator.generateAndSendReadings(100);
}
};
