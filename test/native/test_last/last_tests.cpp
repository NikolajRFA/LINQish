//
// Created by nrfad on 23-05-2025.
//
#include "iterable.hpp"
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

void last_listOfIntegers_returnsLastInteger()
{
    std::list<int> integers = { 1, 2, 3 };

    int* lastInteger = last<int>(integers);

    TEST_ASSERT_EQUAL_INT(3, *lastInteger);
}

void last_listOfAnimals_returnsLastAnimal()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = last<Animal>(animals);

    TEST_ASSERT_EQUAL_STRING("Sasu", lastAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", lastAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, lastAnimal->age);
}

void last_listOfAnimalsAndPredicate_returnsLastAnimalFittingPredicate()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = last<Animal>(animals, [](const Animal& animal){ return animal.name == "Kira"; });

    TEST_ASSERT_EQUAL_STRING("Kira", lastAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", lastAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, lastAnimal->age);
}

void last_listofAnimalsAndPredicate_nullptr()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* lastAnimal = last<Animal>(animals, [](const Animal& animal){ return animal.species == "dog"; });

    TEST_ASSERT_NULL(lastAnimal);
}

void last_emptyList_nullptr()
{
    std::list<int> integers = {};

    int* lastInt = last<int>(integers);

    TEST_ASSERT_NULL(lastInt);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(last_listOfIntegers_returnsLastInteger);
    RUN_TEST(last_listOfAnimals_returnsLastAnimal);
    RUN_TEST(last_listOfAnimalsAndPredicate_returnsLastAnimalFittingPredicate);
    RUN_TEST(last_listofAnimalsAndPredicate_nullptr);
    RUN_TEST(last_emptyList_nullptr);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
