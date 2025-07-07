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

#ifndef SUM_TESTS
#define SUM_TESTS

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

void sum_listOfIntegers_sumOfList()
{
    LINQish<int> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int sum = integers.sum([](const int &x)
                           { return x; });

    TEST_ASSERT_EQUAL_INT(45, sum);
}

void sum_emptyList_returnsZero()
{
    LINQish<int> numbers = {};

    int total = numbers.sum([](const int &x)
                            { return x; });

    TEST_ASSERT_EQUAL_INT(0, total);
}

void sum_constantSelector_countsElements()
{
    LINQish<std::string> names = {"Kira", "Sasu", "Lulu"};

    int count = names.sum([](const std::string &)
                          { return 1; });

    TEST_ASSERT_EQUAL_INT(3, count);
}

void sum_animalsByAge_returnsTotalAge()
{
    LINQish<Animal> animals = {
        {"Kira", "bird", 3},
        {"Sasu", "bird", 5},
        {"Lulu", "dog", 4}};

    int totalAge = animals.sum([](const Animal &a)
                               { return a.age; });

    TEST_ASSERT_EQUAL_INT(12, totalAge);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(sum_listOfIntegers_sumOfList);
    RUN_TEST(sum_emptyList_returnsZero);
    RUN_TEST(sum_constantSelector_countsElements);
    RUN_TEST(sum_animalsByAge_returnsTotalAge);
    return UNITY_END();
}

#endif // SUM_TESTS
