#ifndef SENDER_H_
#define SENDER_H_

#include <string>
#include <vector>
#include <random>
#include <tuple>

class Sender {
 public:
    void generateAndSendReadings(int numReadings);
    void sendReading(int temp, int pulse, int spo2);
};

#endif  // SENDER_H_
