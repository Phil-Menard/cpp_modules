#include "ScavTrap.hpp"

unsigned int ScavTrap::_energyPoints = 50;

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : Claptrap(name, 100, ScavTrap::_energyPoints, 20)
{
	std::cout << "ScavTrap name constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : Claptrap(copy)
{
	std::cout << "Copy ScavTrap constructor called." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	std::cout << "Affectation ScavTrap operator called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
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