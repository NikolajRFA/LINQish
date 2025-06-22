﻿/*
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
// Created by nrfad on 16-05-2025.
//
#include <list>
#include <functional>
#include "linqish.h"
#include "unity.h"


void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void any_listOfNumbers0to9_numberIsOver5IsTrue() {
    std::list<int> initList;
    for (int i = 0; i < 10; i++) {
        initList.push_back(i);
    }
    LINQish<int> list(initList);

    auto resultList = list.filter([](const int& x) { return x > 4;} ).toList();

    for (int i = 5; i < 10; i++) 
    {
        TEST_ASSERT_EQUAL_INT(i, resultList.front());
        resultList.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, resultList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(any_listOfNumbers0to9_numberIsOver5IsTrue);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
