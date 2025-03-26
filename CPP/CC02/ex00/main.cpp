#include "Fixed.hpp"

int main(void) 
{
	Fixed a;			// Calls default constructor
	Fixed b(a);			// Calls copy constructor and assignement opertor
	Fixed c;			// Calls default constructor
	c = b;				// Calls copy assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

