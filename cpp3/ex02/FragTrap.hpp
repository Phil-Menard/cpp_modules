#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"

class FragTrap : public Claptrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();

		void	highFivesGuys();
};

#endif