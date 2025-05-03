#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

static bool isChar(const std::string &str) 
{
	return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

static bool isFloat(const std::string &str) 
{
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;

	std::istringstream iss(str.substr(0, str.length() - 1));
	float f;
	iss >> f;
	return !iss.fail() && iss.eof();
}

static bool isDouble(const std::string &str) 
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;

	std::istringstream iss(str);
	double d;
	iss >> d;
	return !iss.fail() && iss.eof();
}

static bool isInt(const std::string &str) 
{
	std::istringstream iss(str);
	int i;
	iss >> i;
	return !iss.fail() && iss.eof();
}

void ScalarConverter::convert(std::string const & literal) 
{
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal)) 
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
	} 
	else if (isInt(literal)) 
	{
		int i = atoi(literal.c_str());
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << static_cast<float>(i) << "f\n";
		std::cout << "double: " << static_cast<double>(i) << "\n";
	} 
	else if (isFloat(literal)) 
	{
		float f = static_cast<float>(atof(literal.c_str()));
		if (std::isnan(f) || std::isinf(f)) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		} 
		else 
		{
			if (f >= 32 && f <= 126)
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;

			std::cout << "int: " << static_cast<int>(f) << std::endl;
		}
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else if (isDouble(literal))
	{
		double d = atof(literal.c_str());

		if (std::isnan(d) || std::isinf(d)) 
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		} 
		else 
		{
			if (d >= 32 && d <= 126)
				std::cout << "char: '" << static_cast<char>(d) << "'\n";
			else
				std::cout << "char: Non displayable\n";

			std::cout << "int: " << static_cast<int>(d) << "\n";
		}

		std::cout << "float: " << static_cast<float>(d) << "f\n";
		std::cout << "double: " << d << "\n";
	}
	else 
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
}

