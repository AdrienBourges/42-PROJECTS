#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    type = "WrongCat";
    std::cout << "WrongCat constructed\n";
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destroyed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    WrongAnimal::operator=(other);
    std::cout << "WrongCat assigned\n";
    return *this;
}

void WrongCat::makeSound() const 
{
    std::cout << "Miaou??\n";
}

