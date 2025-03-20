#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string givenName);  // Constructor
	~Zombie();                 // Destructor
	void announce() const;      // Announce function
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

