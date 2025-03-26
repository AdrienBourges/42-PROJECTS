#include "Fixed.hpp"
#include <cmath> // for roundf

// Default constructor
Fixed::Fixed() : _rawBits(0) 
{
	std::cout << "Default constructor called\n";
}

// Int constructor
Fixed::Fixed(const int n) 
{
	std::cout << "Int constructor called\n";
	_rawBits = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float f) 
{
	std::cout << "Float constructor called\n";
	_rawBits = roundf(f * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;

}

// Copy assignment
Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed() 
{
	std::cout << "Destructor called\n";
}

// Getter
int Fixed::getRawBits(void) const 
{
	return this->_rawBits;
}

// Setter
void Fixed::setRawBits(int const raw) 
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

// Convert fixed-point to float
float Fixed::toFloat(void) const 
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

// Convert fixed-point to int
int Fixed::toInt(void) const 
{
	return _rawBits >> _fractionalBits;
}

// Overload <<
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return out;
}

