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

//
// Created by nrfad on 08-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Initialize test setup if needed
}

void tearDown()
{
    // Clean up after tests if needed
}

/**
 * @brief Tests `minBy` on a list of integers.
 */
void minBy_listOfIntegers_smallestInteger()
{
    LINQish<int> integers = {4, 2, 6, 1, 3};

    auto integer = integers.minBy<int>([](int a) { return a; });

    TEST_ASSERT_NOT_NULL(integer);
    TEST_ASSERT_EQUAL_INT(1, *integer);
}

/**
 * @brief Tests `minBy` on a list of animals, finding the youngest.
 */
void minBy_listOfAnimals_youngestAnimal()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 9),
        Animal("Kira", "bird", 9),
        Animal("Allan", "hamster", 2)};

    auto animal = animals.minBy<int>([](const Animal& a) { return a.age; });

    TEST_ASSERT_NOT_NULL(animal);
    TEST_ASSERT_EQUAL_STRING("Allan", animal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", animal->species.c_str());
    TEST_ASSERT_EQUAL_INT(2, animal->age);
}

/**
 * @brief Tests `minBy` on an empty list.
 */
void minBy_emptyList_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.minBy<int>([](int a) { return a; });

    TEST_ASSERT_NULL(integer);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(minBy_listOfIntegers_smallestInteger);
    RUN_TEST(minBy_listOfAnimals_youngestAnimal);
    RUN_TEST(minBy_emptyList_nullptr);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
