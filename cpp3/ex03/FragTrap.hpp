#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class FragTrap : virtual public Claptrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();

		void	highFivesGuys();

	protected:
		static const int _hitPoints = 100;
		static const unsigned int _attackDamage = 42;
};

#endif