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
// Created by nrfad on 20-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Setup logic if needed
}

void tearDown()
{
    // Teardown logic if needed
}

/**
 * @brief Tests skipping integers less than 4.
 */
void skipWhile_listOfIntegers_skipLessThan4()
{
    LINQish<int> numbers = {1, 2, 3, 4, 5};

    numbers.skipWhile([](int x) { return x < 4; });

    std::list<int> result = numbers.toList();

    TEST_ASSERT_EQUAL_INT(2, result.size());
    TEST_ASSERT_EQUAL_INT(4, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(5, result.front()); result.pop_front();
}

/**
 * @brief Tests skipping animals while species == "bird".
 */
void skipWhile_listOfAnimals_skipBirds()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 5),
        Animal("Kira", "bird", 6),
        Animal("Benny", "cat", 2),
        Animal("Lulu", "dog", 4)};

    animals.skipWhile([](const Animal& a) {
        return a.species == "bird";
    });

    std::list<Animal> result = animals.toList();

    TEST_ASSERT_EQUAL_INT(2, result.size());
    TEST_ASSERT_EQUAL_STRING("Benny", result.front().name.c_str()); result.pop_front();
    TEST_ASSERT_EQUAL_STRING("Lulu", result.front().name.c_str()); result.pop_front();
}

/**
 * @brief Tests skipping on an empty list.
 */
void skipWhile_emptyList_noCrash()
{
    LINQish<int> numbers = {};
    numbers.skipWhile([](int x) { return x < 10; });

    std::list<int> result = numbers.toList();
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(skipWhile_listOfIntegers_skipLessThan4);
    RUN_TEST(skipWhile_listOfAnimals_skipBirds);
    RUN_TEST(skipWhile_emptyList_noCrash);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
