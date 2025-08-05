#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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
		static const unsigned int _defaultEnergyPoints;
};

#endif