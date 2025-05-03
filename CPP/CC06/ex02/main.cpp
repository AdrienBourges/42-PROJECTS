#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void);
void	identify(Base *);
void	identify(Base &);

int	main() 
{
	for (int i = 0; i < 5; ++i) 
	{
		Base *p = generate();
		std::cout << "identify(Base*)  : ";
		identify(p);

		std::cout << "identify(Base&)  : ";
		identify(*p);

		delete p;
		std::cout << "---------------------------" << std::endl;
	}
	return 0;
}

