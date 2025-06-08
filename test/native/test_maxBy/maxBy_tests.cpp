//
// Created by nrfad on 08-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Initialize test setup if needed
}

void tearDown()
{
    // Clean up after tests if needed
}

/**
 * @brief Tests `maxBy` on a list of integers.
 */
void maxBy_listOfIntegers_largestInteger()
{
    LINQish<int> integers = {4, 2, 6, 1, 3};

    auto integer = integers.maxBy<int>([](int a) { return a; });

    TEST_ASSERT_NOT_NULL(integer);
    TEST_ASSERT_EQUAL_INT(6, *integer);
}

/**
 * @brief Tests `maxBy` on a list of animals, finding the oldest.
 */
void maxBy_listOfAnimals_oldestAnimal()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 9),
        Animal("Allan", "hamster", 2)};

    auto animal = animals.maxBy<int>([](const Animal& a) { return a.age; });

    TEST_ASSERT_NOT_NULL(animal);
    TEST_ASSERT_EQUAL_INT(9, animal->age);
    TEST_ASSERT_EQUAL_STRING("bird", animal->species.c_str());
    TEST_ASSERT_EQUAL_STRING("Sasu", animal->name.c_str()); // Either Sasu or Kira
}

/**
 * @brief Tests `maxBy` on an empty list.
 */
void maxBy_emptyList_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.maxBy<int>([](int a) { return a; });

    TEST_ASSERT_NULL(integer);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(maxBy_listOfIntegers_largestInteger);
    RUN_TEST(maxBy_listOfAnimals_oldestAnimal);
    RUN_TEST(maxBy_emptyList_nullptr);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
