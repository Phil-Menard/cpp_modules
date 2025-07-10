#include <math.h>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _fixed(0)
{
}

Fixed::Fixed(Fixed const & copy)
{
	*this = copy;
}

Fixed::Fixed(int const n)
{
	this->_fixed = n << _bits;
}

Fixed::Fixed(float const f)
{
	this->_fixed = roundf(f * (1 << _bits));
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat() const
{
	return (float)this->_fixed / (1 << _bits);
}

int	Fixed::toInt() const
{
	return this->_fixed >> _bits;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	this->_fixed = other.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & other)
{
	o << other.toFloat();
	return o;
}

/**=================================================================
 *!                      OPERATEUR DE COMPARAISON
 *==================================================================**/

bool Fixed::operator>(Fixed const & other) const
{
	return this->_fixed > other._fixed;
}

bool Fixed::operator<(Fixed const & other) const
{
	return this->_fixed < other._fixed;
}

bool Fixed::operator>=(Fixed const & other) const
{
	return this->_fixed >= other._fixed;
}

bool Fixed::operator<=(Fixed const & other) const
{
	return this->_fixed <= other._fixed;
}

bool Fixed::operator==(Fixed const & other) const
{
	return this->_fixed == other._fixed;
}

bool Fixed::operator!=(Fixed const & other) const
{
	return this->_fixed != other._fixed;
}

/**=================================================================
 *!                      OPERATEURS D'ARITHMETIQUES
 *==================================================================**/

Fixed	Fixed::operator+(Fixed const & other) const
{
	Fixed a(this->toFloat() + other.toFloat());
	return a;
}

Fixed	Fixed::operator-(Fixed const & other) const
{
	Fixed a(this->toFloat() - other.toFloat());
	return a;
}

Fixed	Fixed::operator*(Fixed const & other) const
{
	Fixed a(this->toFloat() * other.toFloat());
	return a;
}

Fixed	Fixed::operator/(Fixed const & other) const
{
	Fixed a(this->toFloat() / other.toFloat());
	return a;
}

/**=================================================================
 *!       OPERATEURS D'INCREMENTATIONS ET DE DECREMENTATIONS
 *==================================================================**/

/*
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator++(int);
*/

Fixed & Fixed::operator++()
{	
	this->_fixed++;
	return *this;
} 

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed & Fixed::operator--()
{
	this->_fixed--;
	return *this;
} 

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}

/**=================================================================
 *!                     FONCTIONS MIN ET MAX
 *==================================================================**/

Fixed Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	else
		return b;
}
