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

void copyConstructor_listOfIntegers_copyHasIdenticalList()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    LINQish<int> copy(numbers);
    copy.concat({5});
    auto copyVector = copy.toVector();

    TEST_ASSERT_EQUAL_INT(5, copyVector.size());
    for (int i = 1; i < 5; i++)
    {
        TEST_ASSERT_EQUAL_INT(i, copyVector[i - 1]);
    }
    TEST_ASSERT_EQUAL_INT(4, numbers.toList().size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(copyConstructor_listOfIntegers_copyHasIdenticalList);
    return UNITY_END();
}

#endif // COPYCONSTRUCTOR_TESTS
