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
// Created by nrfad on 22-05-2025.
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

void all_listOfNumbers0to9AllNumbersAreOver5_False() {
    std::list<int> initList;
    for (int i = 0; i < 10; i++) {
        initList.push_back(i);
    }
    LINQish<int> list(initList);

    bool result = list.all([](const int& x){ return x > 5; });

    TEST_ASSERT_EQUAL_INT(0, result);
}

void all_listOfAnimalsAllAreCalledKira_False()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    bool result = animals.all([](const Animal& animal){ return animal.name == "Kira"; });

    TEST_ASSERT_EQUAL_INT(0, result);
}

void all_listOfAnimalsAllAreBirds_True()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    bool result = animals.all([](const Animal& animal){ return animal.species == "bird"; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

void all_listOfIntegersAllAreOver5_True()
{
    LINQish<int> integers = { 6, 7, 8, 9, 10 };

    bool result = integers.all([](const int& x){ return x > 5; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(all_listOfNumbers0to9AllNumbersAreOver5_False);
    RUN_TEST(all_listOfAnimalsAllAreCalledKira_False);
    RUN_TEST(all_listOfAnimalsAllAreBirds_True);
    RUN_TEST(all_listOfIntegersAllAreOver5_True);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
