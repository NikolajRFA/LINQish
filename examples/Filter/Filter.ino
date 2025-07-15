#include <Arduino.h>
#include <linqish.h>

void setup()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto filteredIntegersVector = integers.filter([](const int &x) { return x > 5; }).toVector();

    for (int i = 0; i < filteredIntegersVector.size(); i++)
    {
        Serial.println(filteredIntegersVector[i]);
    }
}

void loop() {}
