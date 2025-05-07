#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int main(int argc, char* argv[]) 
{
	if (argc < 2) 
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int> v;
	for (int i = 1; i < argc; ++i) 
	{
		std::string s(argv[i]);
		for (size_t j = 0; j < s.size(); ++j)
			if (!std::isdigit(s[j])) 
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		v.push_back(std::atoi(s.c_str()));
	}
	std::cout << "Before:";
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << ' ' << v[i];
	std::cout << std::endl;
	std::vector<int> v_copy(v.begin(), v.end());
	std::deque<int> d(v.begin(), v.end());
	clock_t start = std::clock();
	mergeInsertSort(v_copy);
	clock_t end = std::clock();

double timeV = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
	std::cout << "After:";
	for (size_t i = 0; i < v_copy.size(); ++i)
		std::cout << ' ' << v_copy[i];
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << timeV << " us" << std::endl;
	start = std::clock();
	mergeInsertSort(d);
	end = std::clock();

double timeD = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : "
		<< std::fixed << std::setprecision(5) << timeD << " us" << std::endl;
	return 0;
}
