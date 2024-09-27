#include "./sender.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>
#include <sstream>
#include <iostream>

// Test case for generateRandomReadings
TEST(SenderTest, GenerateRandomReadingsTest) {
    Sender sender;
    int numReadings = 10;
    auto readings = sender.generateRandomReadings(numReadings);

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
TEST(SenderTest, SendReadingTest_MockedCout) {
    Sender sender;

    // Redirect std::cout to a stringstream to capture the output
    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(); // Save the old buffer
    std::cout.rdbuf(buffer.rdbuf());                      // Redirect std::cout

    // Test with specific values
    int temp = 98;
    int pulse = 75;
    int spo2 = 95;
    sender.sendReading(temp, pulse, spo2);

    // Restore the original buffer
    std::cout.rdbuf(oldCoutStreamBuf);

    // Expected output
    std::string expectedOutput =
        "Temperature: 98°F\n"
        "Pulse Rate: 75 bpm\n"
        "SPO2: 95%\n\n";

    // Verify that the captured output matches the expected output
    EXPECT_EQ(buffer.str(), expectedOutput);
}
