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


#ifndef COPYCONSTRUCTOR_TESTS
#define COPYCONSTRUCTOR_TESTS

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

void copyConstructor_listOfIntegers_copyHasIdenticalCopiedList()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    LINQish<int> copy(numbers);
    copy.concat({5});
    auto copyVector = copy.toVector();

    TEST_ASSERT_EQUAL_INT(4, numbers.toList().size());
    TEST_ASSERT_EQUAL_INT(5, copyVector.size());
    for (int i = 1; i < 5; i++)
    {
        TEST_ASSERT_EQUAL_INT(i, copyVector[i - 1]);
    }
}

void copyConstructor_listOfAnimals_copyHasIdenticalCopiedList()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    LINQish<Animal> copy(animals);
    copy.concat({ Animal("Allan", "hamster", 2) });
    auto copyVector = copy.toVector();

    TEST_ASSERT_EQUAL_INT(2, animals.toList().size());
    TEST_ASSERT_EQUAL_INT(3, copyVector.size());
    TEST_ASSERT_EQUAL_STRING("Kira", copyVector[0].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", copyVector[0].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, copyVector[0].age);
    TEST_ASSERT_EQUAL_STRING("Sasu", copyVector[1].name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", copyVector[1].species.c_str());
    TEST_ASSERT_EQUAL_INT(9, copyVector[1].age);
    TEST_ASSERT_EQUAL_STRING("Allan", copyVector[2].name.c_str());
    TEST_ASSERT_EQUAL_STRING("hamster", copyVector[2].species.c_str());
    TEST_ASSERT_EQUAL_INT(2, copyVector[2].age);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(copyConstructor_listOfIntegers_copyHasIdenticalCopiedList);
    RUN_TEST(copyConstructor_listOfAnimals_copyHasIdenticalCopiedList);
    return UNITY_END();
}

#endif // COPYCONSTRUCTOR_TESTS
