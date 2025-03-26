#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) 
{
	std::cout << "Default constructor called\n";
}

// Copy constructor
Fixed::Fixed(const Fixed& other):_rawBits(other._rawBits) 
{
	std::cout << "Copy constructor called\n";
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) 
	{
		this->_rawBits = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() 
{
	std::cout << "Destructor called\n";
}

// Getter function
int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called\n";
	return this->_rawBits;
}

// Setter function
void Fixed::setRawBits(int const raw) 
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

