#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main()
{
	std::vector<int> v;
	for (int i = 0; i < 5; ++i)
		v.push_back(i * 5);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << *it << std::endl;
		it = easyfind(v, 42);
		std::cout << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

