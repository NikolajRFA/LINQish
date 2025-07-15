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
    LINQish<float> floats = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    auto integers = floats
        .map<int>([](const float &x) { return floor(x); })
        .toVector();

    for (int i = 0; i < integers.size(); i++)
    {
        Serial.println(integers[i]); // 1, 2, 3, 4, 5
    }
}

void loop() {}
