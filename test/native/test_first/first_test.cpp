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

void first_listOfIntegers_returnsFirstInteger()
{
    std::list<int> list = { 1, 2, 3 };

    int* firstInteger = first<int>(list);

    TEST_ASSERT_EQUAL_INT(1, *firstInteger);
}

void first_listOfAnimals_returnsFirstAnimal()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = first<Animal>(animals);

    TEST_ASSERT_EQUAL_STRING("Kira", firstAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", firstAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, firstAnimal->age);
}

void first_listOfAnimalsAndPredicate_returnsFirstAnimalFittingPredicate()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = first<Animal>(animals, [](const Animal& animal){ return animal.name == "Sasu"; });

    TEST_ASSERT_EQUAL_STRING("Sasu", firstAnimal->name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", firstAnimal->species.c_str());
    TEST_ASSERT_EQUAL_INT(9, firstAnimal->age);
}

void first_listOfAnimalsAndPredicate_nullptr()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    Animal* firstAnimal = first<Animal>(animals, [](const Animal& animal){ return animal.species == "dog"; });

    TEST_ASSERT_NULL(firstAnimal);
}

void first_emptyList_nullptr()
{
    std::list<int> integers = {};

    int* firstInt = first<int>(integers);

    TEST_ASSERT_NULL(firstInt);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(first_listOfIntegers_returnsFirstInteger);
    RUN_TEST(first_listOfAnimals_returnsFirstAnimal);
    RUN_TEST(first_listOfAnimalsAndPredicate_returnsFirstAnimalFittingPredicate);
    RUN_TEST(first_listOfAnimalsAndPredicate_nullptr);
    RUN_TEST(first_emptyList_nullptr);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
