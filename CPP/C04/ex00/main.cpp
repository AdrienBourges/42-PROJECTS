#include "Animal.hpp"
#include "Dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << "\n";
    std::cout << i->getType() << "\n";
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "---------- Wrong Animals -----------\n";

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << "\n";
    wrongCat->makeSound();
    wrong->makeSound();

    delete wrong;
    delete wrongCat;

    return 0;
}

