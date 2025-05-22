//
// Created by nrfad on 21-05-2025.
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

void any_listOfNumbers0to9_numberIsOver5_True() {
    std::list<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }

    bool result = any<int>(list, [](const int& x){ return x > 5; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

void any_listOfAnimals_anyIsCalledKira_True()
{
    std::list<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    bool result = any<Animal>(animals, [](const Animal& animal){ return animal.name == "Kira"; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(any_listOfNumbers0to9_numberIsOver5_True);
    RUN_TEST(any_listOfAnimals_anyIsCalledKira_True);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
