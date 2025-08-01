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


#ifndef TOVECTOR_TESTS
#define TOVECTOR_TESTS

#include <list>
#include <vector>
#include "linqish.h"
#include "../animal.hpp"
#include "unity.h"

void setUp()
{
    // Setup logic if needed
}

void tearDown()
{
    // Teardown logic if needed
}

/**
 * @brief Tests `toVector()` on a populated LINQish list.
 */
void toVector_populatedList_correctValues()
{
    LINQish<int> numbers = { 1, 2, 3, 4, 5 };
    std::vector<int> vec = numbers.toVector();

    TEST_ASSERT_EQUAL_INT(5, vec.size());

    for (int i = 0; i < vec.size(); ++i)
    {
        TEST_ASSERT_EQUAL_INT(i + 1, vec[i]);
    }
}

void toVector_listPopulatedWithAnimals_correctValues()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9), Animal("Allan", "hamster", 2) };
    auto vec = animals.toVector();

    TEST_ASSERT_EQUAL_INT(3, vec.size());

    TEST_ASSERT_EQUAL_STRING("Kira", vec[0].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", vec[0].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, vec[0].age);
    TEST_ASSERT_EQUAL_STRING("Sasu", vec[1].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", vec[1].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, vec[1].age);
    TEST_ASSERT_EQUAL_STRING("Allan", vec[2].name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", vec[2].species.c_str());
    TEST_ASSERT_EQUAL_INT(2, vec[2].age);
}

/**
 * @brief Tests `toVector()` on an empty LINQish list.
 */
void toVector_emptyList_returnsEmptyVector()
{
    LINQish<int> numbers = {};
    std::vector<int> vec = numbers.toVector();

    TEST_ASSERT_EQUAL_INT(0, vec.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(toVector_populatedList_correctValues);
    RUN_TEST(toVector_emptyList_returnsEmptyVector);
    RUN_TEST(toVector_listPopulatedWithAnimals_correctValues);
    return UNITY_END();
}

#endif // TOVECTOR_TESTS
