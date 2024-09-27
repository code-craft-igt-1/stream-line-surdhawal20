#include "./sender.h"
#include <iostream>

std::tuple<int, int, int> generateRandomReading(std::mt19937* gen) {
    std::uniform_int_distribution<> temperatureRange(95, 100);
    std::uniform_int_distribution<> pulseRange(60, 100);
    std::uniform_int_distribution<> spo2Range(90, 100);

    int temp = temperatureRange(*gen);
    int pulse = pulseRange(*gen);
    int spo2 = spo2Range(*gen);

    return std::make_tuple(temp, pulse, spo2);
}

void Sender::generateAndSendReadings(int numReadings) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());  // Initialize generator with random device

    // Send each reading by calling sendReading
    for (int i = 0; i < numReadings; ++i) {
        auto [temp, pulse, spo2] = generateRandomReading(&gen);  // Reuse the helper function
        sendReading(temp, pulse, spo2);
    }
}

void Sender::sendReading(int temp, int pulse, int spo2) {
    std::cout << "Temperature: " << temp << "°F" << std::endl;
    std::cout << "Pulse Rate: " << pulse << " bpm" << std::endl;
    std::cout << "SPO2: " << spo2 << "%" << std::endl;
    std::cout << std::endl;
}

int main() {
    Sender sender;
    sender.generateAndSendReadings(50);
    return 0;
}
