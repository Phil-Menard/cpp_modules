#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Point const & copy) : x(copy.x), y(copy.y)
{
}

Point::Point(float const a, float const b) : x(a), y(b)
{
}

Point::~Point()
{
}

//don't do anything because x and y are const
Point & Point::operator=(Point const & other)
{
	(void) other;
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
