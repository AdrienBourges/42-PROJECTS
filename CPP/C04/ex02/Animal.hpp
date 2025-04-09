#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	virtual void makeSound() const = 0; // Pure virtual function: makes Animal an abstract class
	std::string getType() const;
};

#endif

