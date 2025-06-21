//
// Created by nrfad on 09-06-2025.
//
#include <list>
#include "linqish.h"
#include "unity.h"
#include "../../animal.hpp"

void setUp()
{
    // Setup code (if needed)
}

void tearDown()
{
    // Cleanup code (if needed)
}

/**
 * @brief Test contains(value) with an existing integer.
 */
void contains_value_integerExists_returnsTrue()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    bool result = numbers.contains(3);
    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains(value) with a non-existing integer.
 */
void contains_value_integerMissing_returnsFalse()
{
    LINQish<int> numbers = { 1, 2, 3, 4 };

    bool result = numbers.contains(10);
    TEST_ASSERT_FALSE(result);
}

/**
 * @brief Test contains(predicate) for even number in list.
 */
void contains_predicate_evenNumber_returnsTrue()
{
    LINQish<int> numbers = { 1, 3, 5, 8 };

    bool result = numbers.contains([](int x) { return x % 2 == 0; });
    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains(predicate) when no predicate matches.
 */
void contains_predicate_nothingMatches_returnsFalse()
{
    LINQish<int> numbers = { 1, 3, 5 };

    bool result = numbers.contains([](int x) { return x > 10; });
    TEST_ASSERT_FALSE(result);
}

/**
 * @brief Test contains(predicate) on animal species.
 */
void contains_predicate_speciesMatches_returnsTrue()
{
    LINQish<Animal> animals = {
        Animal("Sasu", "bird", 5),
        Animal("Kira", "bird", 6),
        Animal("Lulu", "dog", 4)
    };

    bool result = animals.contains([](const Animal& a) {
        return a.species == "dog";
    });

    TEST_ASSERT_TRUE(result);
}

/**
 * @brief Test contains() on an empty list.
 */
void contains_emptyList_returnsFalse()
{
    LINQish<int> numbers = {};

    TEST_ASSERT_FALSE(numbers.contains(1));
    TEST_ASSERT_FALSE(numbers.contains([](int x) { return true; }));
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(contains_value_integerExists_returnsTrue);
    RUN_TEST(contains_value_integerMissing_returnsFalse);
    RUN_TEST(contains_predicate_evenNumber_returnsTrue);
    RUN_TEST(contains_predicate_nothingMatches_returnsFalse);
    RUN_TEST(contains_predicate_speciesMatches_returnsTrue);
    RUN_TEST(contains_emptyList_returnsFalse);
    return UNITY_END();
}

int main()
{
    return runUnityTests();
}
