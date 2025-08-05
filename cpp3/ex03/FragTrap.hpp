#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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