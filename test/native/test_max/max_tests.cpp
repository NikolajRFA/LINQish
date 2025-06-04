//
// Created by nrfad on 04-06-2025.
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

void max_listOfIntegers_largestInteger()
{
    LINQish<int> integers = { 4, 2, 6, 1, 3 };

    auto integer = integers.max([](int a, int b) { return a < b; });

    TEST_ASSERT_EQUAL_INT(6, *integer);
}

void max_emptyListOfIntegers_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.max([](int a, int b) { return a < b; });

    TEST_ASSERT_NULL(integer);
}

void max_listOfAnimals_oldestAnimal()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Allan", "hamster", 2) };

    auto animal = animals.max([](Animal a, Animal b) { return a.age < b.age; });

    TEST_ASSERT_EQUAL_STRING("Sasu", animal->name.c_str()); // Sasu or Kira (both age 9)
    TEST_ASSERT_EQUAL_STRING("bird", animal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animal->age);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(max_listOfIntegers_largestInteger);
    RUN_TEST(max_emptyListOfIntegers_nullptr);
    RUN_TEST(max_listOfAnimals_oldestAnimal);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
