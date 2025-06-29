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


#ifndef SIZE_TESTS
#define SIZE_TESTS

#include <list>
#include "linqish.h"
#include "unity.h"
#include "../animal.hpp"

void setUp()
{
    // Initialize test setup if needed
}

void tearDown()
{
    // Clean up after tests if needed
}

void size_listOfIntegers_sizeReturnsCorrectSize()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5 };

    int size = integers.size();

    TEST_ASSERT_EQUAL_INT(5, size);
}

void size_listOfAnimals_sizeReturnsCorrectSize()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9) };

    int size = animals.size();

    TEST_ASSERT_EQUAL_INT(2, size);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(size_listOfIntegers_sizeReturnsCorrectSize);
    RUN_TEST(size_listOfAnimals_sizeReturnsCorrectSize);
    return UNITY_END();
}

#endif // SIZE_TESTS
