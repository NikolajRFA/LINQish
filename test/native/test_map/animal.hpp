#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
    std::string name;
    std::string species;
    int age;

    Animal(std::string name, std::string species, int age)
    {
        this->name = name;
        this->species = species;
        this->age = age;
    }
};
#endif // ANIMAL_HPP