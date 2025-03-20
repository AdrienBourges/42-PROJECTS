#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie(name);  // Creates a zombie on the stack
    zombie.announce();
}

