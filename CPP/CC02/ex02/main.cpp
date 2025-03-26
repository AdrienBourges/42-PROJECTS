#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{

	std::cout << "\n=== Subject Main ===\n";
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n=== Arithmetic ===\n";
	Fixed x(10.5f);
	Fixed y(2.25f);
	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << "\n=== Comparisons ===\n";
	std::cout << "x == y? " << (x == y) << std::endl;
	std::cout << "x != y? " << (x != y) << std::endl;
	std::cout << "x > y? " << (x > y) << std::endl;
	std::cout << "x < y? " << (x < y) << std::endl;
	std::cout << "x >= y? " << (x >= y) << std::endl;
	std::cout << "x <= y? " << (x <= y) << std::endl;

	std::cout << "\n=== Decrement ===\n";
	std::cout << "x: " << x << std::endl;
	std::cout << "--x: " << --x << std::endl;
	std::cout << "x--: " << x-- << std::endl;
	std::cout << "x after x--: " << x << std::endl;

	return 0;
}
