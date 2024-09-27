#include <gtest/gtest.h>
#include <tuple>
#include <vector>
#include <sstream>
#include <iostream>
#include "./sender.h"

// Utility function to generate random values (same as production)
std::tuple<int, int, int> generateRandomReading(std::mt19937* gen);

// Test case for generateRandomReadings
TEST(SenderTest, GenerateRandomReadingsTest) {
    Sender sender;
    int numReadings = 10;

    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    std::vector<std::tuple<int, int, int>> readings;
    for (int i = 0; i < numReadings; ++i) {
        readings.push_back(generateRandomReading(&gen));
    }

    // Check if the vector size matches the requested number of readings
    ASSERT_EQ(readings.size(), numReadings);

    // Check if generated readings fall within the expected range
    for (const auto& reading : readings) {
        int temp = std::get<0>(reading);
        int pulse = std::get<1>(reading);
        int spo2 = std::get<2>(reading);

        // Validate ranges for each component
        EXPECT_GE(temp, 95);
        EXPECT_LE(temp, 100);
        EXPECT_GE(pulse, 60);
        EXPECT_LE(pulse, 100);
        EXPECT_GE(spo2, 90);
        EXPECT_LE(spo2, 100);
    }
}

// Test case for sendReading with mocked std::cout
TEST(SenderTest, GenerateAndSendReadingsTest_MockedCout) {
    Sender sender;

    // Redirect std::cout to a stringstream to capture the output
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();  // Save the old buffer
    std::cout.rdbuf(buffer.rdbuf());                      // Redirect std::cout

    int numReadings = 3;
    sender.generateAndSendReadings(numReadings);

    // Restore the original buffer
    std::cout.rdbuf(oldCoutStreamBuf);
    std::string output = buffer.str();

    EXPECT_NE(output.find("Temperature: "), std::string::npos);
    EXPECT_NE(output.find("Pulse Rate: "), std::string::npos);
    EXPECT_NE(output.find("SPO2: "), std::string::npos);
}
