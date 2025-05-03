#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main()
{
	std::cout << "Basic example:" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Too few elements test:" << std::endl;
	Span small(3);
	small.addNumber(42);
	try
	{
		std::cout << small.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Overflow test:" << std::endl;
	Span full(3);
	full.addNumber(1);
	full.addNumber(2);
	full.addNumber(3);
	try
	{
		full.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Sequential range insertion (10 000 elems):" << std::endl;
	std::vector<int> seq;
	for (int i = 0; i < 10000; ++i)
		seq.push_back(i);
	Span seqSpan(10000);
	seqSpan.addNumber(seq.begin(), seq.end());
	std::cout << seqSpan.shortestSpan() << std::endl;
	std::cout << seqSpan.longestSpan() << std::endl;

	std::cout << "Random range insertion (10 000 elems):" << std::endl;
	std::srand(std::time(NULL));
	std::vector<int> rnd;
	for (int i = 0; i < 10000; ++i)
		rnd.push_back(std::rand());
	Span rndSpan(10000);
	rndSpan.addNumber(rnd.begin(), rnd.end());
	std::cout << rndSpan.shortestSpan() << std::endl;
	std::cout << rndSpan.longestSpan() << std::endl;

	return 0;
}

