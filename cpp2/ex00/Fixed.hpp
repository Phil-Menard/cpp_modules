#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const & copy);
		~Fixed();
		Fixed & operator=(Fixed const & new_fixed);

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_fixed;
		static const int	_bits;
};

#endif