//
// Created by nrfad on 23-05-2025.
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

void skip_listOfIntegersSkip3_restOfList()
{
    std::list<int> integers = { 1, 2, 3, 4, 5, 6 };

    integers = LINQish<int>(integers).skip(3).toList();

    TEST_ASSERT_EQUAL_INT(4, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(5, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(6, integers.front());
    integers.pop_front();
    TEST_ASSERT_EQUAL_INT(0, integers.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(skip_listOfIntegersSkip3_restOfList);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
