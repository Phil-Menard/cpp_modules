#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point const a(1.0f, 1.0f);
	Point const b(4.0f, 1.0f);
	Point const c(2.0f, 4.0f);

	//POINT INSIDE
	Point const p1(2.0f, 2.0f);
	bsp(a, b, c, p1);

	//POINT OUTSIDE
	Point const p2(0.0f, 0.0f);
	bsp(a, b, c, p2);

	//POINT ON EDGE
	Point const p3(2.5f, 1.0f);
	bsp(a, b, c, p3);

	return 0;
}
