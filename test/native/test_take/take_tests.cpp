//
// Created by nrfad on 26-05-2025.
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

void take_listOfIntegersTake3_gets3FirstIntegers()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6 };

    auto integerList = integers.take(3).toList();

    TEST_ASSERT_EQUAL_INT(1, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(2, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(3, integerList.front());
    integerList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, integerList.size());
}

void take_listOfAnimalsTake2_getsFirst2Animals()
{
    LINQish<Animal> animals = { Animal("Sasu", "bird", 9), Animal("Kira", "bird", 9), Animal("Allan", "hamster", 2) };

    auto animalList = animals.take(2).toList();

    TEST_ASSERT_EQUAL_STRING("Sasu", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_STRING("Kira", animalList.front().name.c_str());
    TEST_ASSERT_EQUAL_STRING("bird", animalList.front().species.c_str());
    TEST_ASSERT_EQUAL_INT(9, animalList.front().age);
    animalList.pop_front();
    TEST_ASSERT_EQUAL_INT(0, animalList.size());
}

void take_listOfIntegersTakeMoreThanPresent_wholeListIsReturned()
{
    LINQish<int> integers = { 1, 2, 3, 4, 5, 6 };

    auto integerList = integers.take(10).toList();

    for (int i = 1; i <= 6; ++i)
    {
        TEST_MESSAGE("i: " + i);
        TEST_ASSERT_EQUAL_INT(i, integerList.front());
        integerList.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, integerList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(take_listOfIntegersTake3_gets3FirstIntegers);
    RUN_TEST(take_listOfAnimalsTake2_getsFirst2Animals);
    RUN_TEST(take_listOfIntegersTakeMoreThanPresent_wholeListIsReturned);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
