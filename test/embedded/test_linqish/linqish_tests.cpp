/*
 Copyright (c) 2025-present Nikolaj Andersen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

//
// Created by nrfad on 26-06-2025.
//
#include "Arduino.h"
#include "../../shared/linqish_tests.h"

void setUp()
{
    // Setup code (if needed)
}

void tearDown()
{
    // Cleanup code (if needed)
}

int runUnityTests()
{
    UNITY_BEGIN();
    RUN_TEST(linqish_filterAndAny_true);
    RUN_TEST(linqish_filterAndSkipWhile_leavesRest);
    RUN_TEST(linqish_filterTakeSkip_expectedOrder);
    RUN_TEST(linqish_concatDistinctTakeWhile);
    RUN_TEST(linqish_filterSkipWhileFirst);
    RUN_TEST(linqish_filterMapDistinctTake);
    RUN_TEST(linqish_concatSkipTakeWhileAll);
    RUN_TEST(linqish_filterSkipConcatFirst);
    RUN_TEST(linqish_mapContains);
    RUN_TEST(linqish_filterBySpeciesAndTake_returnsExpectedAnimals);
    RUN_TEST(linqish_mapToAges_anyOlderThanFive);
    RUN_TEST(linqish_firstOlderThanFive_returnsCorrectAnimal);
    return UNITY_END();
}

void setup()
{
    delay(2000);

    runUnityTests();
}

void loop() {}