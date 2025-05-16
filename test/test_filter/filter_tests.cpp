//
// Created by nrfad on 16-05-2025.
//
#include <HardwareSerial.h>
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

    TEST_ASSERT_EQUAL_INT(5, list.front());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(6, list.front());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(7, list.front());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(8, list.front());
    list.pop_front();
    TEST_ASSERT_EQUAL_INT(9, list.front());
    list.pop_front();
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
void setup()
{
    Serial.begin(115200);
    // Wait ~2 seconds before the Unity test runner
    // establishes connection with a board Serial interface
    delay(2000);
    Serial.println("Test starting...");
    runUnityTests();
}
void loop() {}
