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
		Fixed & operator=(Fixed const & new_fixed);

		//OPERATEUR DE COMPARAISON
		bool operator>(Fixed const & new_fixed) const;
		bool operator<(Fixed const & new_fixed) const;
		bool operator<=(Fixed const & new_fixed) const;
		bool operator>=(Fixed const & new_fixed) const;
		bool operator!=(Fixed const & new_fixed) const;
		bool operator==(Fixed const & new_fixed) const;

		//OPERATEURS DE ARITHMETIQUES
		Fixed operator+(Fixed const & new_fixed) const;
		Fixed operator-(Fixed const & new_fixed) const;
		Fixed operator*(Fixed const & new_fixed) const;
		Fixed operator/(Fixed const & new_fixed) const;

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_fixed;
		static const int	_bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & new_fixed);

#endif