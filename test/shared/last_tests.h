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


#ifndef LAST_TESTS
#define LAST_TESTS

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

void last_listOfIntegers_returnsLastInteger()
{
    LINQish<int> integers = { 1, 2, 3 };

    int* lastInteger = integers.last();

    TEST_ASSERT_EQUAL_INT(3, *lastInteger);
}

void last_listOfAnimals_returnsLastAnimal()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = animals.last();

    TEST_ASSERT_EQUAL_STRING("Sasu", lastAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", lastAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, lastAnimal->age);
}

void last_listOfAnimalsAndPredicate_returnsLastAnimalFittingPredicate()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = animals.last([](const Animal& animal){ return animal.name == "Kira"; });

    TEST_ASSERT_EQUAL_STRING("Kira", lastAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", lastAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, lastAnimal->age);
}

void last_listofAnimalsAndPredicate_nullptr()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = animals.last([](const Animal& animal){ return animal.species == "dog"; });

    TEST_ASSERT_NULL(lastAnimal);
}

void last_emptyList_nullptr()
{
    LINQish<int> integers = {};

    int* lastInt = integers.last();

    TEST_ASSERT_NULL(lastInt);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(last_listOfIntegers_returnsLastInteger);
    RUN_TEST(last_listOfAnimals_returnsLastAnimal);
    RUN_TEST(last_listOfAnimalsAndPredicate_returnsLastAnimalFittingPredicate);
    RUN_TEST(last_listofAnimalsAndPredicate_nullptr);
    RUN_TEST(last_emptyList_nullptr);
    return UNITY_END();
}

#endif // LAST_TESTS
