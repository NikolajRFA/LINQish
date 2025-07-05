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


#ifndef REVERSE_TESTS
#define REVERSE_TESTS

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

void reverse_listOfIntergers_reversedList()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5 };

    auto reversed = integers.reverse().toList();

    for (int i = 5; i > 0; i--)
    {
        TEST_ASSERT_EQUAL_INT(i, reversed.front());
        reversed.pop_front();
    }
}

void reverse_listOfAnimals_reversedList()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9), Animal("Allan", "hamster", 2) };

    auto reversed = animals.reverse().toVector();

    TEST_ASSERT_EQUAL_STRING("Allan", reversed[0].name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", reversed[0].species.c_str());
    TEST_ASSERT_EQUAL_INT(2, reversed[0].age);
    TEST_ASSERT_EQUAL_STRING("Kira", reversed[1].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", reversed[1].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, reversed[1].age);
    TEST_ASSERT_EQUAL_STRING("Sasu", reversed[2].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", reversed[2].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, reversed[2].age);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(reverse_listOfIntergers_reversedList);
    RUN_TEST(reverse_listOfAnimals_reversedList);
    return UNITY_END();
}

#endif // REVERSE_TESTS
