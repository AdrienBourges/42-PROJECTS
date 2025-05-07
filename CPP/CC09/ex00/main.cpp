#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>

bool validDate(const std::string& d) 
{
	int y, m, day;
	if (sscanf(d.c_str(), "%d-%d-%d", &y, &m, &day) != 3)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

bool validValue(const std::string& v, double& out) 
{
	char* end;
	double val = std::strtod(v.c_str(), &end);
	if (end == v.c_str() || *end != '\0')
		return false;
	out = val;
	return true;
}

int main(int argc, char* argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	try 
	{
		btc.loadDatabase("data.csv");
	} 
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::ifstream in(argv[1]);
	if (!in) 
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(in, line)) 
	{
		if (line.empty() || line.find("date | value") == 0)
			continue;
		std::istringstream iss(line);
		std::string date, sep, valueStr;
		if (!(iss >> date >> sep >> valueStr) || sep != "|" || !validDate(date)) 
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		double value;
		if (!validValue(valueStr, value)) 
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value < 0) 
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) 
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try 
		{
			double rate = btc.getRate(date);
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} 
		catch (const std::out_of_range&) 
		{
			std::cerr << "Error: no earlier date available for " << date << std::endl;
		}
	}
	return 0;
}
