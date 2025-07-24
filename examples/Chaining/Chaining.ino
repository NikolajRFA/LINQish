/*
 Copyright (c) 2025-present Nikolaj Andersen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#include <Arduino.h>
#include <linqish.h>

void setup()
{
    Serial.begin(115200);
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
