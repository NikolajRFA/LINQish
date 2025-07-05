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

#ifndef FILTER_TESTS
#define FILTER_TESTS

#include <list>
#include "linqish.h"
#include "unity.h"
#include "../animal.hpp"

void setUp()
{
    // Setup code (if needed)
}

void tearDown()
{
    // Cleanup code (if needed)
}

void filter_listOfNumbers0to9_numberIsOver5IsTrue()
{
    std::list<int> initList;
    for (int i = 0; i < 10; i++)
    {
        initList.push_back(i);
    }
    LINQish<int> list(initList);

    auto resultList = list.filter([](const int &x)
                                  { return x > 4; })
                          .toList();

    for (int i = 5; i < 10; i++)
    {
        TEST_ASSERT_EQUAL_INT(i, resultList.front());
        resultList.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, resultList.size());
}

void filter_listOfAnimals_birdsAreLeft()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird" ,9), Animal("Kira", "bird", 9), Animal("Allan", "hamster", 2) };

    auto filteredAnimals = animals.filter([](const Animal &animal) { return animal.species == "bird"; }).toList();

    TEST_ASSERT_EQUAL_INT(2, filteredAnimals.size());
    TEST_ASSERT_EQUAL_STRING("Sasu", filteredAnimals.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", filteredAnimals.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, filteredAnimals.front().age);
    filteredAnimals.pop_front();
    TEST_ASSERT_EQUAL_STRING("Kira", filteredAnimals.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", filteredAnimals.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, filteredAnimals.front().age);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(filter_listOfNumbers0to9_numberIsOver5IsTrue);
    RUN_TEST(filter_listOfAnimals_birdsAreLeft);
    return UNITY_END();
}

#endif // FILTER_TESTS