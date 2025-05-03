#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void print(const T& x)
{
	std::cout << x << std::endl;
}

template<typename T>
void increment(T& x)
{
	++x;
}

int main()
{
	int ia[5] = {0, 1, 2, 3, 4};
	iter(ia, 5, print<int>);
	iter(ia, 5, increment<int>);
	iter(ia, 5, print<int>);

	std::string sa[3] = {"foo", "bar", "baz"};
	iter(sa, 3, print<std::string>);

	return 0;
}

