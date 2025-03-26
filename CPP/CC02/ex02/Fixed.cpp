#include "Fixed.hpp"
#include <cmath>

// Orthodox Canonical Form
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed& other) 
{ 
	*this = other; 
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() { }

// Custom constructors
Fixed::Fixed(const int n) 
{ 
	_rawBits = n << _fractionalBits; 
}

Fixed::Fixed(const float f) 
{ 
	_rawBits = roundf(f * (1 << _fractionalBits)); 
}

// Conversion
float Fixed::toFloat(void) const 
{ 
	return (float)_rawBits / (1 << _fractionalBits); 
}

int Fixed::toInt(void) const 
{ 
	return _rawBits >> _fractionalBits; 
}

// Getter/Setter
int Fixed::getRawBits(void) const 
{ 
	return _rawBits; 
}

void Fixed::setRawBits(int const raw)
{ 
	_rawBits = raw; 
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const 
{ 
	return _rawBits > other._rawBits; 
}

bool Fixed::operator<(const Fixed& other) const 
{ 
	return _rawBits < other._rawBits; 
}

bool Fixed::operator>=(const Fixed& other) const 
{ 
	return _rawBits >= other._rawBits; 
}

bool Fixed::operator<=(const Fixed& other) const 
{ 
	return _rawBits <= other._rawBits; 
}

bool Fixed::operator==(const Fixed& other) const 
{ 
	return _rawBits == other._rawBits; 
}

bool Fixed::operator!=(const Fixed& other) const 
{ 
	return _rawBits != other._rawBits; 
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const 
{ 
	return Fixed(this->toFloat() + other.toFloat()); 
}

Fixed Fixed::operator-(const Fixed& other) const 
{ 
	return Fixed(this->toFloat() - other.toFloat()); 
}

Fixed Fixed::operator*(const Fixed& other) const 
{ 
	return Fixed(this->toFloat() * other.toFloat()); 
}

Fixed Fixed::operator/(const Fixed& other) const 
{ 
	return Fixed(this->toFloat() / other.toFloat()); 
}

// Increment / Decrement
Fixed& Fixed::operator++() 
{ 
	++_rawBits; return *this; 
}

Fixed Fixed::operator++(int) 
{ 
	Fixed temp = *this; 
	++_rawBits; return temp; 
}

Fixed& Fixed::operator--() 
{ 
	--_rawBits; 
	return *this; 
}

Fixed Fixed::operator--(int) 
{ 
	Fixed temp = *this; 
	--_rawBits; return temp; 
}

// Static min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) 
{ 
	return a < b ? a : b; 
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{ 
	return a < b ? a : b; 
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{ 
	return a > b ? a : b; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{ 
	return a > b ? a : b; 
}

// Output operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return out;
}

