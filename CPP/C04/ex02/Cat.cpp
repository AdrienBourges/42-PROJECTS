#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) 
{
	type = "Cat";
	std::cout << "Cat constructed\n";
}

Cat::~Cat() 
{
	delete brain;
	std::cout << "Cat destroyed\n";
}

Cat::Cat(const Cat& other) : Animal(other) 
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other) 
{
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat assigned\n";
	return *this;
}

void Cat::makeSound() const 
{
	std::cout << "Meow!\n";
}

void Cat::setIdea(int index, const std::string& idea) 
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const 
{
	return brain->getIdea(index);
}

