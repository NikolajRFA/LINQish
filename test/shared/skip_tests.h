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


#ifndef SKIP_TESTS
#define SKIP_TESTS

#include <list>
#include <functional>
#include "linqish.h"
#include "unity.h"
#include "../animal.hpp"

void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void skip_listOfIntegersSkip3_restOfList()
{
    std::list<int> integers = { 1, 2, 3, 4, 5, 6 };

    integers = LINQish<int>(integers).skip(3).toList();

    TEST_ASSERT_EQUAL_INT(4, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(5, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(6, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(0, integers.size());
}

void skip_listOfAnimalsSkip1_restOfList()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9), Animal("Allan", "hamster", 2) };

    auto animalList = animals.skip(1).toList();

    TEST_ASSERT_EQUAL_STRING("Sasu", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_STRING("Allan", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(2, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, animalList.size());
}

void skip_listOfIntegersSkip5_emptyList()
{
    LINQish<int> integers = { 1, 2, 3, 4 };

    auto integerList = integers.skip(5).toList();

    TEST_ASSERT_EQUAL_INT(1, integerList.empty());
    TEST_ASSERT_EQUAL_INT(0, integerList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(skip_listOfIntegersSkip3_restOfList);
    RUN_TEST(skip_listOfAnimalsSkip1_restOfList);
    RUN_TEST(skip_listOfIntegersSkip5_emptyList);
    return UNITY_END();
}

#endif // SKIP_TESTS
