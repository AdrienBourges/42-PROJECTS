#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) 
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " has been constructed!" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << this->name << " has been destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (hitPoints <= 0 || energyPoints <= 0) 
	{
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " viciously attacks " << target
              << ", dealing " << attackDamage << " damage!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
