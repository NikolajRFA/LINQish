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
// Created by nrfad on 26-05-2025.
//
#include <list>
#include <functional>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void take_listOfIntegersTake3_gets3FirstIntegers()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6 };

    auto integerList = integers.take(3).toList();

    TEST_ASSERT_EQUAL_INT(1, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(2, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(3, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, integerList.size());
}

void take_listOfAnimalsTake2_getsFirst2Animals()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9), Animal("Allan", "hamster", 2) };

    auto animalList = animals.take(2).toList();

    TEST_ASSERT_EQUAL_STRING("Sasu", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_STRING("Kira", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, animalList.size());
}

void take_listOfIntegersTakeMoreThanPresent_wholeListIsReturned()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6 };

    auto integerList = integers.take(10).toList();

    for (int i = 1; i <= 6; ++i)
    {
        TEST_MESSAGE("i: " + i);
        TEST_ASSERT_EQUAL_INT(i, integerList.front());
        integerList.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, integerList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(take_listOfIntegersTake3_gets3FirstIntegers);
    RUN_TEST(take_listOfAnimalsTake2_getsFirst2Animals);
    RUN_TEST(take_listOfIntegersTakeMoreThanPresent_wholeListIsReturned);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
