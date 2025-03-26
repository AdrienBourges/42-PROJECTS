// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	// Orthodox Canonical Form
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	// Constructors
	Fixed(const int n);
	Fixed(const float f);

	// Conversion methods
	float toFloat(void) const;
	int toInt(void) const;

	// Getter/Setter
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment / Decrement
	Fixed& operator++();		// pre-increment
	Fixed operator++(int);		// post-increment
	Fixed& operator--();		// pre-decrement
	Fixed operator--(int);		// post-decrement

	// Static min/max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

