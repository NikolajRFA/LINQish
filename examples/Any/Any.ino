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
#include <string>

void setup()
{
    Serial.begin(115200);
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6 };

    bool anyOver5 = integers.any([](const int &x) { return x > 5; });

    Serial.print("anyOver5: ");
    Serial.println(anyOver5);
}

void loop() {}
