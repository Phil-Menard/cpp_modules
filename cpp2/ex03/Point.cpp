#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(Point const & copy)
{
	*this = copy;
}

Point::Point(float const a, float const b) : x(a), y(b)
{

}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

Point & Point::operator=(Point const & other)
{
	(void) other;
	return *this;
}

void Point::setVectors(Point a, Point b)
{
	
}
