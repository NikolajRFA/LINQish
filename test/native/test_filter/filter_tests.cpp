//
// Created by nrfad on 16-05-2025.
//
#include <list>
#include <functional>
#include "linqish.h"
#include "unity.h"


void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void any_listOfNumbers0to9_numberIsOver5IsTrue() {
    std::list<int> initList;
    for (int i = 0; i < 10; i++) {
        initList.push_back(i);
    }
    LINQish<int> list(initList);

    auto resultList = list.filter([](const int& x) { return x > 4;} ).toList();

    for (int i = 5; i < 10; i++) 
    {
        TEST_ASSERT_EQUAL_INT(i, resultList.front());
        resultList.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, resultList.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(any_listOfNumbers0to9_numberIsOver5IsTrue);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
