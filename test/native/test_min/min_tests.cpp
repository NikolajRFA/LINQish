//
// Created by nrfad on 01-06-2025.
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

void min_listOfIntegers_smallestInteger()
{
    LINQish<int> integers = { 4, 2, 6, 1, 3 };

    auto integer = integers.min([](int a, int b) { return a < b; });

    TEST_ASSERT_EQUAL_INT(1, *integer);
}

void min_emptyListOfIntegers_nullptr()
{
    LINQish<int> integers = {};

    auto integer = integers.min([](int a, int b) { return a < b; });

    TEST_ASSERT_NULL(integer);
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(min_listOfIntegers_smallestInteger);
    RUN_TEST(min_emptyListOfIntegers_nullptr);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
