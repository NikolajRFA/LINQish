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
// Created by nrfad on 23-05-2025.
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

void first_listOfIntegers_returnsFirstInteger()
{
    LINQish<int> list = { 1, 2, 3 };

    int* firstInteger = list.first();

    TEST_ASSERT_EQUAL_INT(1, *firstInteger);
}

void first_listOfAnimals_returnsFirstAnimal()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = animals.first();

    TEST_ASSERT_EQUAL_STRING("Kira", firstAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", firstAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, firstAnimal->age);
}

void first_listOfAnimalsAndPredicate_returnsFirstAnimalFittingPredicate()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = animals.first([](const Animal& animal){ return animal.name == "Sasu"; });

    TEST_ASSERT_EQUAL_STRING("Sasu", firstAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", firstAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, firstAnimal->age);
}

void first_listOfAnimalsAndPredicate_nullptr()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = animals.first([](const Animal& animal){ return animal.species == "dog"; });

    TEST_ASSERT_NULL(firstAnimal);
}

void first_emptyList_nullptr()
{
    LINQish<int> integers = {};

    int* firstInt = integers.first();

    TEST_ASSERT_NULL(firstInt);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(first_listOfIntegers_returnsFirstInteger);
    RUN_TEST(first_listOfAnimals_returnsFirstAnimal);
    RUN_TEST(first_listOfAnimalsAndPredicate_returnsFirstAnimalFittingPredicate);
    RUN_TEST(first_listOfAnimalsAndPredicate_nullptr);
    RUN_TEST(first_emptyList_nullptr);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
