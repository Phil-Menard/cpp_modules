#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float const a, float const b);
		Point(Point const & copy);
		Point & operator=(Point const & other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
		void setVectors(Point a, Point b);

	private:
		const Fixed x;
		const Fixed y;

		struct vectors
		{
			Point a;
			Point b;
		};
};

#endif