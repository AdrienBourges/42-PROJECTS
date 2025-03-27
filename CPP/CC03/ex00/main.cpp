#include "ClapTrap.hpp"

int main() 
{
    ClapTrap ct("T-Rap");

    ct.attack("enemy bot");
    ct.takeDamage(3);
    ct.beRepaired(5);
    ct.attack("another bot");
    ct.takeDamage(20);
    ct.attack("final bot");
    ct.beRepaired(10);

    return 0;
}

