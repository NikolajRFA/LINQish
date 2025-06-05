//
// Created by nrfad on 06-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"

void setUp()
{
    // Initialize test setup if needed
}

void tearDown()
{
    // Clean up after tests if needed
}

void concat_initializerList_appendsElements()
{
    LINQish<int> numbers = {1, 2, 3};
    numbers.concat({4, 5, 6});

    auto result = numbers.toList();
    
    TEST_ASSERT_EQUAL_INT(6, result.size());
    TEST_ASSERT_EQUAL_INT(1, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(2, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(3, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(4, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(5, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(6, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

void concat_stdList_appendsElements()
{
    LINQish<int> numbers = {1, 2, 3};
    std::list<int> additionalNumbers = {4, 5, 6};
    
    numbers.concat(additionalNumbers);

    auto result = numbers.toList();
    
    TEST_ASSERT_EQUAL_INT(6, result.size());
    TEST_ASSERT_EQUAL_INT(1, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(2, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(3, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(4, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(5, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(6, result.front()); result.pop_front();
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

void concat_multipleTimes_chainsCorrectly()
{
    LINQish<int> numbers = {1, 2, 3};
    
    numbers.concat({4, 5}).concat({6, 7}).concat(std::list<int>{8, 9, 10});
    
    auto result = numbers.toList();
    
    TEST_ASSERT_EQUAL_INT(10, result.size());
    for (int i = 1; i <= 10; ++i)
    {
        TEST_ASSERT_EQUAL_INT(i, result.front());
        result.pop_front();
    }
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(concat_initializerList_appendsElements);
    RUN_TEST(concat_stdList_appendsElements);
    RUN_TEST(concat_multipleTimes_chainsCorrectly);
    return UNITY_END();
}

/**
 * For Arduino framework
 */
int main()
{
    return runUnityTests();
}
