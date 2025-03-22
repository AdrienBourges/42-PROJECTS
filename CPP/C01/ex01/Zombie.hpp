#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string givenName);
	~Zombie();  

	void setName(std::string newName);
	void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif

