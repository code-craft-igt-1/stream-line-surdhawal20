#include "./sender.h"
#include <iostream>

void Sender::generateAndSendReadings(int numReadings) {
    std::vector<std::tuple<int, int, int>> readings = generateRandomReadings(numReadings);

    // Send each reading by calling sendReading
    for (const auto& reading : readings) {
        int temp = std::get<0>(reading);
        int pulse = std::get<1>(reading);
        int spo2 = std::get<2>(reading);
        sendReading(temp, pulse, spo2);  // Call sendReading here
    }
}

std::vector<std::tuple<int, int, int>> Sender::generateRandomReadings(int numReadings) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());  // Initialize generator with random device
    std::uniform_int_distribution<> temperatureRange(95, 100);
    std::uniform_int_distribution<> pulseRange(60, 100);
    std::uniform_int_distribution<> spo2Range(90, 100);

    std::vector<std::tuple<int, int, int>> readings;

    for (int i = 0; i < numReadings; ++i) {
        int temp = temperatureRange(gen);
        int pulse = pulseRange(gen);
        int spo2 = spo2Range(gen);
        readings.push_back(std::make_tuple(temp, pulse, spo2));
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
