#include "ScavTrap.hpp"

unsigned int ScavTrap::_energyPoints = 50;

ScavTrap::ScavTrap()
{

}

ScavTrap::ScavTrap(std::string name) : Claptrap(name, 100, ScavTrap::_energyPoints, 20)
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in guard mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout << "ScavTrap " << this->_name << " attacks " << target;
			std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
			this->_energyPoints--;
		}
		else
			displayNotEnoughEnergy("attack");
	}
}