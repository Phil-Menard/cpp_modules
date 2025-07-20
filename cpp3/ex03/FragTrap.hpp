#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class FragTrap : virtual public Claptrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & copy);
		FragTrap & operator=(FragTrap const & other);
		~FragTrap();

		void	highFivesGuys();

	protected:
		static int _hitPoints;
		static unsigned int _attackDamage;
};

#endif