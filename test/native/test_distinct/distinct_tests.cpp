//
// Created by nrfad on 20-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Optional setup before each test
}

void tearDown()
{
    // Optional cleanup after each test
}

/**
 * @brief Tests distinct on integers with duplicates.
 */
void distinct_listOfIntegers_removesDuplicates()
{
    LINQish<int> numbers = {1, 2, 3, 2, 1, 4, 5, 4};

    numbers.distinct();
    auto result = numbers.toList();

    std::list<int> expected = {1, 2, 3, 4, 5};

    TEST_ASSERT_EQUAL_INT(expected.size(), result.size());

    auto it1 = expected.begin();
    auto it2 = result.begin();
    while (it1 != expected.end())
    {
        TEST_ASSERT_EQUAL_INT(*it1, *it2);
        ++it1;
        ++it2;
    }
}

/**
 * @brief Tests distinct on an empty list.
 */
void distinct_emptyList_noCrash()
{
    LINQish<int> numbers = {};
    numbers.distinct();

    auto result = numbers.toList();
    TEST_ASSERT_EQUAL_INT(0, result.size());
}

/**
 * @brief Tests distinct on a list of animals with duplicate names.
 */
void distinct_listOfAnimals_removesDuplicatesByValue()
{
    LINQish<std::string> names = {
        "Kira", "Sasu", "Kira", "Lulu", "Sasu", "Mika"};

    names.distinct();
    auto result = names.toList();

    std::list<std::string> expected = {
        "Kira", "Sasu", "Lulu", "Mika"};

    TEST_ASSERT_EQUAL_INT(expected.size(), result.size());

    auto it1 = expected.begin();
    auto it2 = result.begin();
    while (it1 != expected.end())
    {
        TEST_ASSERT_EQUAL_STRING(it1->c_str(), it2->c_str());
        ++it1;
        ++it2;
    }
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(distinct_listOfIntegers_removesDuplicates);
    RUN_TEST(distinct_emptyList_noCrash);
    RUN_TEST(distinct_listOfAnimals_removesDuplicatesByValue);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
