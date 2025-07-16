#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point const a(1.0f, 1.0f);
	Point const b(4.0f, 1.0f);
	Point const c(2.0f, 4.0f);
	Point const p(2.0f, 2.0f);

	bsp(a, b, c, p);

	return 0;
}
