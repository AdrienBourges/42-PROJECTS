#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    std::cout << "=== CLAPTRAP ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target A");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== SCAVTRAP ===" << std::endl;
    ScavTrap scav("Scavy");
    scav.attack("Target B");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== FRAGTRAP ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target C");
    frag.takeDamage(50);
    frag.beRepaired(25);
    frag.highFivesGuys();

    return 0;
}

