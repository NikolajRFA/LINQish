//
// Created by nrfad on 16-05-2025.
//
#include "iterable.hpp"
#include "unity.h"
#include <string>
#include "animal.hpp"
#include "pet.hpp"

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
    std::list<std::string> list = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};

    list = map<std::string, std::string>(list, [](const std::string &s)
                                         { return s.substr(0, 3); });

    TEST_ASSERT_EQUAL_STRING("aaa", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("bbb", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("ccc", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("ddd", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("eee", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(0, list.size());
}

void map_listOfAnimals_listOfPets()
{
    std::list<Animal> animalList = {Animal("Zazu", "bird", 9), Animal("Kira", "bird", 9)};

    std::list<Pet> petList = map<Animal, Pet>(animalList, [](const Animal &animal) { return Pet(animal.name, animal.species, animal.age, "Selin"); });

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

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
