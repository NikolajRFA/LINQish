//
// Created by nrfad on 21-05-2025.
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

void any_listOfNumbers0to9_numberIsOver5_True() {
    std::list<int> initList;
    for (int i = 0; i < 10; i++) {
        initList.push_back(i);
    }
    LINQish<int> list(initList);

    bool result = list.any([](const int& x){ return x > 5; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

void any_listOfAnimals_anyIsCalledKira_True()
{
    LINQish<Animal> animals = { Animal("Kira", "bird", 9), Animal("Sasu", "bird", 9) };

    bool result = animals.any([](const Animal& animal){ return animal.name == "Kira"; });

    TEST_ASSERT_EQUAL_INT(1, result);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(any_listOfNumbers0to9_numberIsOver5_True);
    RUN_TEST(any_listOfAnimals_anyIsCalledKira_True);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
