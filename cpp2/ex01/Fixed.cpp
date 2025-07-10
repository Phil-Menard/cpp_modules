#include <math.h>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructeur called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = n << _bits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(f * (1 << _bits));
}

Fixed & Fixed::operator=(Fixed const & new_fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = new_fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & new_fixed)
{
	o << new_fixed.toFloat();
	return o;
}
