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