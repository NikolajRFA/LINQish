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


#ifndef AVERAGE_TESTS
#define AVERAGE_TESTS

#include <list>
#include "linqish.h"
#include "unity.h"
#include "../animal.hpp"

void setUp()
{
    // Initialize test setup if needed
}

void tearDown()
{
    // Clean up after tests if needed
}

void average_listOfIntegers_averageInteger()
{
    LINQish<int> integers = { 2, 3, 4 };

    int average = integers.average([](const int &x) { return x; });

    TEST_ASSERT_EQUAL_INT(3, average);
}

void average_listOfFloats_averageFloat()
{
    LINQish<float> floats = { 2.5, 5.0, 7.5, 10.0 };

    float average = floats.average([](const float &x) { return x; });

    TEST_ASSERT_EQUAL_FLOAT(6.25, average);
}

void average_listOfAnimals_averageAge()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9), Animal("Allan", "hamster", 2) };

    float average = animals.average([](const Animal &animal) { return animal.age; });

    TEST_ASSERT_EQUAL_FLOAT(6.666666, average);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(average_listOfIntegers_averageInteger);
    RUN_TEST(average_listOfFloats_averageFloat);
    RUN_TEST(average_listOfAnimals_averageAge);
    return UNITY_END();
}

#endif // AVERAGE_TESTS
