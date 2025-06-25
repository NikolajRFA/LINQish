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

#ifndef LINQISH_TESTS
#define LINQISH_TESTS

#include <list>
#include "linqish.h"
#include "unity.h"
#include "../animal.hpp"

void setUp()
{
    // Optional setup before each test
}

void tearDown()
{
    // Optional cleanup after each test
}

void linqish_filterAndAny_true()
{
    LINQish<int> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    bool result = integers.filter([](const int &x)
                                  { return x > 4; })
                      .any([](const int &x)
                           { return x == 9; });

    TEST_ASSERT_TRUE(result);
}

void linqish_filterAndSkipWhile_leavesRest()
{
    LINQish<int> integers = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};

    std::list<int> result = integers.filter([](const int &x)
                                            { return x > 4; })
                                .skipWhile([](const int &x)
                                           { return x < 10; })
                                .toList();

    TEST_ASSERT_EQUAL_INT(3, result.size());
    for (int i = 10; i < 12; i++)
    {
        TEST_ASSERT_EQUAL_INT(i, result.front());
        result.pop_front();
    }
}

void linqish_filterTakeSkip_expectedOrder()
{
    LINQish<int> numbers = {1, 2, 3, 4, 5, 6};

    numbers
        .filter([](int x)
                { return x % 2 == 0; }) // Keep evens: 2, 4, 6
        .skip(1)                        // Skip 2 → 4, 6
        .take(1);                       // Take 4

    auto result = numbers.toList();
    std::list<int> expected = {4};

    TEST_ASSERT_EQUAL_INT(expected.size(), result.size());

    auto it1 = expected.begin();
    auto it2 = result.begin();
    while (it1 != expected.end())
    {
        TEST_ASSERT_EQUAL_INT(*it1, *it2);
        ++it1;
        ++it2;
    }
}

void linqish_concatDistinctTakeWhile()
{
    LINQish<int> nums = {3, 1, 2, 3};

    nums
        .concat({4, 1, 5}) // → 3,1,2,3,4,1,5
        .distinct()        // → 3,1,2,4,5
        .takeWhile([](int x)
                   { return x < 5; }); // → 3,1,2,4

    std::list<int> expected = {3, 1, 2, 4};
    auto result = nums.toList();

    TEST_ASSERT_EQUAL_INT(expected.size(), result.size());

    auto it1 = expected.begin();
    auto it2 = result.begin();
    while (it1 != expected.end())
    {
        TEST_ASSERT_EQUAL_INT(*it1, *it2);
        ++it1;
        ++it2;
    }
}

void linqish_filterSkipWhileFirst()
{
    LINQish<int> nums = {1, 3, 5, 6, 7, 8, 10};

    nums
        .filter([](int x)
                { return x > 3; }) // → 5,6,7,8,10
        .skipWhile([](int x)
                   { return x < 7; }); // → 7,8,10

    int *result = nums.first();
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT(7, *result);
}

void linqish_filterMapDistinctTake()
{
    LINQish<int> nums = {1, 2, 2, 3, 4, 5, 5};

    auto result = nums
                      .filter([](int x)
                              { return x > 2; }) // 3, 4, 5, 5
                      .map<int>([](int x)
                                { return x * 2; }) // 6, 8, 10, 10
                      .distinct()                  // 6, 8, 10
                      .take(2)                     // 6, 8
                      .toList();

    std::list<int> expected = {6, 8};

    TEST_ASSERT_EQUAL_INT(expected.size(), result.size());
    auto it1 = expected.begin();
    auto it2 = result.begin();
    while (it1 != expected.end())
    {
        TEST_ASSERT_EQUAL_INT(*it1, *it2);
        ++it1;
        ++it2;
    }
}

void linqish_concatSkipTakeWhileAll()
{
    LINQish<int> nums = {1, 2, 3};

    bool result = nums
                      .concat({4, 5, 6, 7, 8})
                      .skipWhile([](int x)
                                 { return x < 5; }) // 5, 6, 7, 8
                      .takeWhile([](int x)
                                 { return x <= 7; }) // 5, 6, 7
                      .all([](int x)
                           { return x % 2 != 0 || x == 6; }); // true

    TEST_ASSERT_TRUE(result);
}

void linqish_filterSkipConcatFirst()
{
    LINQish<std::string> words = {"apple", "banana", "avocado", "berry"};

    std::string *result = words
                              .filter([](const std::string &s)
                                      { return s[0] == 'a'; }) // apple, avocado
                              .skip(1)                         // avocado
                              .concat({"apricot", "almond"})   // avocado, apricot, almond
                              .first([](const std::string &s)
                                     { return s.size() == 6; }); // almond

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("almond", result->c_str());
}

void linqish_mapContains()
{
    LINQish<int> numbers = {1, 2, 3, 4};

    bool result = numbers
                      .map<std::string>([](int x)
                                        { return std::to_string(x * 10); }) // "10", "20", "30", "40"
                      .contains([](const std::string &s)
                                { return s == "30"; });

    TEST_ASSERT_TRUE(result);
}

void linqish_filterBySpeciesAndTake_returnsExpectedAnimals()
{
    LINQish<Animal> animals = {
        {"Kira", "bird", 3},
        {"Sasu", "bird", 5},
        {"Lulu", "dog", 4},
        {"Mika", "dog", 6}};

    animals
        .filter([](const Animal &a)
                { return a.species == "dog"; }) // Lulu, Mika
        .take(1);                               // Lulu

    auto result = animals.toList();
    TEST_ASSERT_EQUAL_INT(1, result.size());
    TEST_ASSERT_EQUAL_STRING("Lulu", result.front().name.c_str());
}

void linqish_mapToAges_anyOlderThanFive()
{
    LINQish<Animal> animals = {
        {"Sasu", "bird", 5},
        {"Allan", "hamster", 2},
        {"Mika", "dog", 6}};

    bool result = animals
                      .map<int>([](const Animal &a)
                                { return a.age; })
                      .any([](int age)
                           { return age > 5; }); // true (Mika)

    TEST_ASSERT_TRUE(result);
}

void linqish_firstOlderThanFive_returnsCorrectAnimal()
{
    LINQish<Animal> animals = {
        {"Kira", "bird", 3},
        {"Lulu", "dog", 4},
        {"Mika", "dog", 6}};

    Animal *result = animals.first([](const Animal &a)
                                   { return a.age > 5; });

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING("Mika", result->name.c_str());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(linqish_filterAndAny_true);
    RUN_TEST(linqish_filterAndSkipWhile_leavesRest);
    RUN_TEST(linqish_filterTakeSkip_expectedOrder);
    RUN_TEST(linqish_concatDistinctTakeWhile);
    RUN_TEST(linqish_filterSkipWhileFirst);
    RUN_TEST(linqish_filterMapDistinctTake);
    RUN_TEST(linqish_concatSkipTakeWhileAll);
    RUN_TEST(linqish_filterSkipConcatFirst);
    RUN_TEST(linqish_mapContains);
    RUN_TEST(linqish_filterBySpeciesAndTake_returnsExpectedAnimals);
    RUN_TEST(linqish_mapToAges_anyOlderThanFive);
    RUN_TEST(linqish_firstOlderThanFive_returnsCorrectAnimal);
    return UNITY_END();
}

#endif // LINQISH_TESTS