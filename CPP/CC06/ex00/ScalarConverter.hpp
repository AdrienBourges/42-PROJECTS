#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter 
{
public:
	static void convert(std::string const & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter & operator=(ScalarConverter const &);
	~ScalarConverter();
};

#endif

