#include <Arduino.h>
#include <linqish.h>

void setup()
{
    LINQish<int> numbers = {1, 2, 3, 4, 5, 6};

    auto integersVector = numbers
        .filter([](int x)
                { return x % 2 == 0; }) // Keep evens: 2, 4, 6
        .skip(1)                        // Skip 2 → 4, 6
        .take(1)                        // Take 4
        .toVector();

    for (int i = 0; i < integersVector.size(); i++)
    {
        Serial.println(integersVector[i]);
    }
}

void loop() {}
