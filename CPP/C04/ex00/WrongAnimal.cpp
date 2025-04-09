#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal constructed\n";
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destroyed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
    std::cout << "WrongAnimal copied\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    type = other.type;
    std::cout << "WrongAnimal assigned\n";
    return *this;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "* wrong generic animal sound *\n";
}

std::string WrongAnimal::getType() const 
{
    return type;
}

