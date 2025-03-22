#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string givenName) : name(givenName) {}

Zombie::~Zombie() 
{
    std::cout << "Zombie " << name << " is destroyed!" << std::endl;
}

void Zombie::setName(std::string newName) 
{
    name = newName;
}

void Zombie::announce() const 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

