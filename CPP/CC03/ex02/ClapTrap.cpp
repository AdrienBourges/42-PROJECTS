#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) 
{
    if (hitPoints <= 0 || energyPoints <= 0) 
	{
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    hitPoints -= amount;
    if (hitPoints < 0) 
		hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (hitPoints <= 0 || energyPoints <= 0) 
	{
        std::cout << "ClapTrap " << name << " cannot repair itself!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, recovering "
              << amount << " hit points!" << std::endl;
}

