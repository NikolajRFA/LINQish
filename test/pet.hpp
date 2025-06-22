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

#ifndef PET_HPP
#define PET_HPP

#include <string>

class Pet
{
public:
    std::string name;
    std::string species;
    int age;
    std::string ownerName;

    Pet(std::string name, std::string species, int age, std::string ownerName)
    {
        this->name = name;
        this->species = species;
        this->age = age;
        this->ownerName = ownerName;
    }
};
#endif // PET_HPP