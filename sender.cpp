#include "./sender.h"
#include <iostream>


void Sender::generateAndSendReadings(int numReadings) {
    generateRandomReadings(numReadings);
}

void Sender::generateRandomReadings(int numReadings) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());  // Initialize generator with random device
    std::uniform_int_distribution<> temperatureRange(95, 100);
    std::uniform_int_distribution<> pulseRange(60, 100);
    std::uniform_int_distribution<> spo2Range(90, 100);

    for (int i = 0; i < numReadings; ++i) {
        int temp = temperatureRange(gen);
        int pulse = pulseRange(gen);
        int spo2 = spo2Range(gen);
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
    Sender generator;
    generator.generateAndSendReadings(50);
    return 0;
}
