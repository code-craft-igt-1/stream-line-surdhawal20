#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "sender.h"

// Helper function to capture the output from std::cout
std::string captureOutput(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer

    func();  // Call the function that generates output

    std::cout.rdbuf(old);  // Reset cout to original state
    return buffer.str();   // Return the captured output
}

TEST(SenderTest, OutputTest) {
    Sender generator;

    // Capture the output of generateAndSendReadings
    std::string output = captureOutput([&]() {
        generator.generateAndSendReadings(1);
        });

    // Check if the output contains valid ranges (basic check)
    EXPECT_TRUE(output.find("Temperature") != std::string::npos);
    EXPECT_TRUE(output.find("Pulse Rate") != std::string::npos);
    EXPECT_TRUE(output.find("SPO2") != std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
