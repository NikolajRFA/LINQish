//
// Created by nrfad on 16-05-2025.
//
#include "iterable.hpp"
#include "unity.h"
#include <string>


void setUp()
{
    // set stuff up here
}

void tearDown()
{
    // clean stuff up here
}

void map_test() {
    std::list<std::string> list = {"aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"};

    list = map<std::string, std::string>(list, [](const std::string& s) { return s.substr(0, 3); });

    TEST_ASSERT_EQUAL_STRING("aaa", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("bbb", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("ccc", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("ddd", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_STRING("eee", list.front().c_str());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(0, list.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(map_test);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
