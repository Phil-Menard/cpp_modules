#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed x, y;

	//VECTOR FROM A TO B
	x = b.getX() - a.getX();
	y = b.getY() - a.getY();
	Point vectAB((x.toFloat()), y.toFloat());

	//VECTOR FROM B TO C
	x = c.getX() - b.getX();
	y = c.getY() - b.getY();
	Point vectBC(x.toFloat(), y.toFloat());

	//VECTOR FROM C TO A
	x = a.getX() - c.getX();
	y = a.getY() - c.getY();
	Point vectCA(x.toFloat(), y.toFloat());

	//VECTOR FROM A TO POINT
	x = point.getX() - a.getX();
	y = point.getY() - a.getY();
	Point vectAP(x.toFloat(), y.toFloat());

	//VECTOR FROM B TO POINT
	x = point.getX() - b.getX();
	y = point.getY() - b.getY();
	Point vectBP(x.toFloat(), y.toFloat());

	//VECTOR FROM C TO POINT
	x = point.getX() - c.getX();
	y = point.getY() - c.getY();
	Point vectCP(x.toFloat(), y.toFloat());

	return true;
}
