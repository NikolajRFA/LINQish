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


#ifndef MAP_TESTS
#define MAP_TESTS

#include <list>
#include <functional>
#include "linqish.h"
#include "unity.h"
#include <string>
#include "../animal.hpp"
#include "../pet.hpp"

void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void map_listOfStrings_listOfSubstrings()
{
    LINQish<std::string> list = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};

    std::list<std::string> mappedList = list.map<std::string>([](const std::string &s)
                                         { return s.substr(0, 3); }).toList();

    TEST_ASSERT_EQUAL_STRING("aaa", mappedList.front().c_str());
    mappedList.pop_front();
    TEST_ASSERT_EQUAL_STRING("bbb", mappedList.front().c_str());
    mappedList.pop_front();
    TEST_ASSERT_EQUAL_STRING("ccc", mappedList.front().c_str());
    mappedList.pop_front();
    TEST_ASSERT_EQUAL_STRING("ddd", mappedList.front().c_str());
    mappedList.pop_front();
    TEST_ASSERT_EQUAL_STRING("eee", mappedList.front().c_str());
    mappedList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, mappedList.size());
}

void map_listOfAnimals_listOfPets()
{
    LINQish<Animal> animalList = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9) };

    std::list<Pet> petList = animalList.map<Pet>([](const Animal &animal) { return Pet(animal.name, animal.species, animal.age, "Selin"); }).toList();

    TEST_ASSERT_EQUAL_STRING("Selin", petList.front().ownerName.c_str());
    petList.pop_front();
    TEST_ASSERT_EQUAL_STRING("Selin", petList.front().ownerName.c_str());
    petList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, petList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(map_listOfStrings_listOfSubstrings);
    RUN_TEST(map_listOfAnimals_listOfPets);
    return UNITY_END();
}

#endif // MAP_TESTS
