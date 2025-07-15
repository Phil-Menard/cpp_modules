#include "Fixed.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	a = 12;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
