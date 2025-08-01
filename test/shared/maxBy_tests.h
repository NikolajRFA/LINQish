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


#ifndef MAXBY_TESTS
#define MAXBY_TESTS

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

/**
 * @brief Tests `maxBy` on a list of integers.
 */
void maxBy_listOfIntegers_largestInteger()
{
    LINQish<int> integers = {4, 2, 6, 1, 3};

    auto integer = integers.maxBy<int>([](int a) { return a; });

    TEST_ASSERT_NOT_NULL(integer);
    TEST_ASSERT_EQUAL_INT(6, *integer);
}

/**
 * @brief Tests `maxBy` on a list of animals, finding the oldest.
 */
void maxBy_listOfAnimals_oldestAnimal()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 9),
        Animal("Allan", "hamster", 2)};

    auto animal = animals.maxBy<int>([](const Animal& a) { return a.age; });

    TEST_ASSERT_NOT_NULL(animal);
    TEST_ASSERT_EQUAL_INT(9, animal->age);
    TEST_ASSERT_EQUAL_STRING("bird", animal->species.c_str());
    TEST_ASSERT_EQUAL_STRING("Sasu", animal->name.c_str()); // Either Sasu or Kira
}

/**
 * @brief Tests `maxBy` on an empty list.
 */
void maxBy_emptyList_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.maxBy<int>([](int a) { return a; });

    TEST_ASSERT_NULL(integer);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(maxBy_listOfIntegers_largestInteger);
    RUN_TEST(maxBy_listOfAnimals_oldestAnimal);
    RUN_TEST(maxBy_emptyList_nullptr);
    return UNITY_END();
}

#endif // MAXBY_TESTS
