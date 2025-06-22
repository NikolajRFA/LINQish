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
// Created by nrfad on 01-06-2025.
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

void min_listOfIntegers_smallestInteger()
{
    LINQish<int> integers = { 4, 2, 6, 1, 3 };

    auto integer = integers.min([](int a, int b) { return a < b; });

    TEST_ASSERT_EQUAL_INT(1, *integer);
}

void min_emptyListOfIntegers_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.min([](int a, int b) { return a < b; });

    TEST_ASSERT_NULL(integer);
}

void min_listOfAnimals_youngestAnimal()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9), Animal("Allan", "hamster", 2) };

    auto animal = animals.min([](Animal a, Animal b) { return a.age < b.age; });

    TEST_ASSERT_EQUAL_STRING("Allan", animal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", animal->species.c_str());
    TEST_ASSERT_EQUAL_INT(2, animal->age);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(min_listOfIntegers_smallestInteger);
    RUN_TEST(min_emptyListOfIntegers_nullptr);
    RUN_TEST(min_listOfAnimals_youngestAnimal);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
