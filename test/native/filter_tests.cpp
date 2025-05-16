//
// Created by nrfad on 16-05-2025.
//
#include "iterable.hpp"
#include "unity.h"


void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void filter_test() {
    std::list<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }

    list = filter<int>(list, [](const int& x) {return x > 4;});

    for (int i = 5; i < 10; i++) 
    {
        TEST_ASSERT_EQUAL_INT(i, list.front());
        list.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, list.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(filter_test);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
