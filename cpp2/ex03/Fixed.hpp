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
		Fixed & operator=(Fixed const & other);

		//OPERATEUR DE COMPARAISON
		bool operator>(Fixed const & other) const;
		bool operator<(Fixed const & other) const;
		bool operator<=(Fixed const & other) const;
		bool operator>=(Fixed const & other) const;
		bool operator!=(Fixed const & other) const;
		bool operator==(Fixed const & other) const;

		//OPERATEURS D'ARITHMETIQUES
		Fixed operator+(Fixed const & other) const;
		Fixed operator-(Fixed const & other) const;
		Fixed operator*(Fixed const & other) const;
		Fixed operator/(Fixed const & other) const;

		//OPERATEURS D'INCREMENTATIONS ET DE DECREMENTATIONS
		Fixed& operator++(); //pre incrementation
		Fixed operator++(int); //post incrementation
		Fixed& operator--(); // pre decrementation
		Fixed operator--(int); // post decrementation

		//FONCTIONS MIN ET MAX
		static Fixed min(Fixed & a, Fixed & b);
		static Fixed min(Fixed const & a, Fixed const & b);
		static Fixed max(Fixed & a, Fixed & b);
		static Fixed max(Fixed const & a, Fixed const & b);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_fixed;
		static const int	_bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & other);

#endif