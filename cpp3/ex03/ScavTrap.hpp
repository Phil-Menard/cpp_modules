#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "Claptrap.hpp"

class ScavTrap : virtual public Claptrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & copy);
		ScavTrap & operator=(ScavTrap const & other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();

	protected:
		static unsigned int _energyPoints;
};

#endif