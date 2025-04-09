#include "cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat constructed\n";
}

Cat::~Cat() 
{
    std::cout << "Cat destroyed\n";
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other)
{
    Animal::operator=(other);
    std::cout << "Cat assigned\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}

