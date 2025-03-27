#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() 
{
    std::cout << "=== CLAPTRAP TEST ===" << std::endl;
    ClapTrap c1("Clappy");
    c1.attack("enemy A");
    c1.takeDamage(4);
    c1.beRepaired(3);

    std::cout << "\n=== SCAVTRAP TEST ===" << std::endl;
    ScavTrap s1("Scavy");
    s1.attack("enemy B");
    s1.takeDamage(20);
    s1.beRepaired(15);
    s1.guardGate();

    return 0;
}

