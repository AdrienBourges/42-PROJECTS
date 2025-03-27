#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap 
{
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
