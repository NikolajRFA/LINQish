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


#ifndef TAKEWHILE_TESTS
#define TAKEWHILE_TESTS

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

void takeWhile_listOfIntegers1To10_returnsAllUnder5()
{
    LINQish<int> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto result = integers.takeWhile([](const int& x){ return x < 5; }).toList();

    for (int i = 1; i < 5; i++)
    {
        TEST_ASSERT_EQUAL_INT(i, result.front());
        result.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

void takeWhile_listOfAnimals_whileAnimalsAreUnder5()
{
    LINQish<Animal> animals = {Animal("Allan", "hamster", 2), Animal("Mr. Wuff", "dog", 4), Animal("Sasu", "bird", 9), Animal("Tux", "cat", 3)};

    auto result = animals.takeWhile([](const Animal& x){ return x.age < 5; }).toList();

    TEST_ASSERT_EQUAL_STRING("Allan", result.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", result.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(2, result.front().age);
    result.pop_front();
    TEST_ASSERT_EQUAL_STRING("Mr. Wuff", result.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("dog", result.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(4, result.front().age);
    result.pop_front();
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

void takeWhile_listOfIntegers_noneAreTaken()
{
    LINQish<int> integers = {1, 2, 3, 4, 5};

    auto result = integers.takeWhile([](const int& x){ return x > 10; }).toList();

    TEST_ASSERT_EQUAL_INT(0, result.size());
}

void takeWhile_emptyList_emptyList()
{
    LINQish<int> integers = {};

    auto result = integers.takeWhile([](const int& x){ return x > 10; }).toList();

    TEST_ASSERT_EQUAL_INT(0, result.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(takeWhile_listOfIntegers1To10_returnsAllUnder5);
    RUN_TEST(takeWhile_listOfAnimals_whileAnimalsAreUnder5);
    RUN_TEST(takeWhile_listOfIntegers_noneAreTaken);
    RUN_TEST(takeWhile_emptyList_emptyList);
    return UNITY_END();
}

#endif // TAKEWHILE_TESTS
