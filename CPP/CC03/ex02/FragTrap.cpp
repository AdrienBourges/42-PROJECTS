#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) 
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " has entered the game!" << std::endl;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap " << this->name << " has left the game!" << std::endl;
}

void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap " << name << " wants a high five! ✋" << std::endl;
}
