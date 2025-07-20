#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class FragTrap : public Claptrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & copy);
		FragTrap & operator=(FragTrap const & other);
		~FragTrap();

		void	highFivesGuys();
};

#endif