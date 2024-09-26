#include "./sender.h"
#include <iostream>

class Sender {
 public:
    void generateAndSendReadings(int numReadings) {
        generateRandomReadings(numReadings);
    }

 private:
    void generateRandomReadings(int numReadings) {
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> temperatureRange(95, 100);
        std::uniform_int_distribution<> pulseDist(60, 100);
        std::uniform_int_distribution<> spo2Dist(90, 100);

        for (int i = 0; i < numReadings; ++i) {
            int temp = temperatureRange(gen);
            int pulse = temperatureRange(gen);
            int spo2 = temperatureRange(gen);
            sendReading(temp, pulse, spo2);
        }
    }

    void sendReading(int temp, int pulse, int spo2) {
        std::cout << "Temperature: " << temp << "°F" << std::endl;
        std::cout << "Pulse Rate: " << pulse << " bpm" << std::endl;
        std::cout << "SPO2: " << spo2 << "%" << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    Sender generator;
    generator.generateAndSendReadings(50);
    return 0;
}
