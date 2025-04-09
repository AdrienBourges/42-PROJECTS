#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) 
	{
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    Dog basic;
    basic.setIdea(0, "Chase cats");
    Dog copy = basic;
    std::cout << "Basic idea: " << basic.getIdea(0) << "\n";
    std::cout << "Copied idea: " << copy.getIdea(0) << "\n";
    basic.setIdea(0, "Sleep");
    std::cout << "After changing basic idea:\n";
    std::cout << "Basic idea: " << basic.getIdea(0) << "\n";
    std::cout << "Copied idea: " << copy.getIdea(0) << "\n";

    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}

