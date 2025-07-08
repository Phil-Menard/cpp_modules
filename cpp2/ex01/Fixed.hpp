#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const & copy);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed();
		Fixed & operator=(Fixed const & rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_fixed;
		static const int	_bits;
};

#endif