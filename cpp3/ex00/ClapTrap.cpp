#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other)
{
	std::cout << "ClapTrap affectation operator called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called." << std::endl;
}

std::string	ClapTrap::getName() const
{
	return this->_name;
}

void ClapTrap::displayNotEnoughEnergy(std::string action) const
{
	std::cout << "ClapTrap " << this->_name << " doesn't got enough energy to " << action << "!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout << "ClapTrap " << this->_name << " attacks " << target;
			std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
			this->_energyPoints--;
		}
		else
			displayNotEnoughEnergy("attack");
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " dealt " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " life points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout << "ClapTrap repaired himself with " << amount << " points!" << std::endl;
			this->_hitPoints += amount;
			this->_energyPoints--;
			std::cout << "ClapTrap " << this->_name << " now has " << this->_hitPoints << " life points" << std::endl;
		}
		else
			displayNotEnoughEnergy("repair himself");
	}
}

void	ClapTrap::displayEnergy()
{
	std::cout << "energyPoints : " <<this->_energyPoints << std::endl;
}