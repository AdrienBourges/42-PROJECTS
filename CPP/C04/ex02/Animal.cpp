#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
	std::cout << "Animal constructed\n";
}

Animal::~Animal() 
{
	std::cout << "Animal destroyed\n";
}

Animal::Animal(const Animal& other) : type(other.type) 
{
	std::cout << "Animal copied\n";
}

Animal& Animal::operator=(const Animal& other) 
{
	type = other.type;
	std::cout << "Animal assigned\n";
	return *this;
}

std::string Animal::getType() const 
{
	return type;
}

