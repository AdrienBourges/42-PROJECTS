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

	// New constructors
	Fixed(const int n);			// from int
	Fixed(const float f);		// from float

	// Conversion methods
	float toFloat(void) const;
	int toInt(void) const;

	// Getter/Setter
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

// Overload of the << operator for std::cout
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

