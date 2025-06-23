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
// Created by nrfad on 21-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Setup code (if needed)
}

void tearDown()
{
    // Cleanup code (if needed)
}

/**
 * @brief Test contains(value) with an existing integer.
 */
void contains_value_integerExists_returnsTrue()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    bool result = numbers.contains(3);
    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains(value) with a non-existing integer.
 */
void contains_value_integerMissing_returnsFalse()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    bool result = numbers.contains(10);
    TEST_ASSERT_FALSE(result);
}

/**
 * @brief Test contains(predicate) for even number in list.
 */
void contains_predicate_evenNumber_returnsTrue()
{
    LINQish<int> numbers = { 1, 3, 5, 8 };

    bool result = numbers.contains([](int x) { return x % 2 == 0; });
    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains(predicate) when no predicate matches.
 */
void contains_predicate_nothingMatches_returnsFalse()
{
    LINQish<int> numbers = { 1, 3, 5 };

    bool result = numbers.contains([](int x) { return x > 10; });
    TEST_ASSERT_FALSE(result);
}

/**
 * @brief Test contains(predicate) on animal species.
 */
void contains_predicate_speciesMatches_returnsTrue()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 5),
        Animal("Kira", "bird", 6),
        Animal("Lulu", "dog", 4)
    };

    bool result = animals.contains([](const Animal& a) {
        return a.species == "dog";
    });

    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains() on an empty list.
 */
void contains_emptyList_returnsFalse()
{
    LINQish<int> numbers = {};

    TEST_ASSERT_FALSE(numbers.contains(1));
    TEST_ASSERT_FALSE(numbers.contains([](int x) { return true; }));
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(contains_value_integerExists_returnsTrue);
    RUN_TEST(contains_value_integerMissing_returnsFalse);
    RUN_TEST(contains_predicate_evenNumber_returnsTrue);
    RUN_TEST(contains_predicate_nothingMatches_returnsFalse);
    RUN_TEST(contains_predicate_speciesMatches_returnsTrue);
    RUN_TEST(contains_emptyList_returnsFalse);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
