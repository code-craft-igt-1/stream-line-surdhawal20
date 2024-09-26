#ifndef READING_GENERATOR_H
#define READING_GENERATOR_H

#include <string>
#include <vector>
#include <random>

class ReadingGenerator {
 public:
    void generateAndSendReadings(int numReadings);

 private:
    std::uniform_int_distribution<> temperatureRange(95, 105);
    std::uniform_int_distribution<> pulseDist(60, 100);
    std::uniform_int_distribution<> spo2Dist(90, 100);

    void generateRandomReadings();
    void sendReading(int temp, int pulse, int spo2);
};

#endif // READING_GENERATOR_H