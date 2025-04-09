#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    std::cout << "Dog constructed\n";
}

Dog::~Dog() 
{
    std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) 
{
    Animal::operator=(other);
    std::cout << "Dog assigned\n";
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "Woof!\n";
}

