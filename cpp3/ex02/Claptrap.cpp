#include "Claptrap.hpp"

Claptrap::Claptrap(std::string name) : _name(name), _hitPoints(10),
									_energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Claptrap constructor called." << std::endl;
}

Claptrap::Claptrap(std::string name, int hitPoints, unsigned int energy, unsigned int damage) :
_name(name), _hitPoints(hitPoints), _energyPoints(energy), _attackDamage(damage)
{
	std::cout << "Second Claptrap constructor called." << std::endl;
}

Claptrap::Claptrap(Claptrap const & other)
{
	std::cout << "Copy Claptrap constructor called." << std::endl;
	*this = other;
}

Claptrap & Claptrap::operator=(Claptrap const & other)
{
	std::cout << "Affectation Claptrap operator called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

Claptrap::~Claptrap()
{
	std::cout << "Claptrap destructor called." << std::endl;
}

std::string	Claptrap::getName() const
{
	return this->_name;
}

void Claptrap::displayNotEnoughEnergy(std::string action) const
{
	std::cout << "Claptrap " << this->_name << " doesn't got enough energy to " << action << "!" << std::endl;
}

void	Claptrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout << "Claptrap " << this->_name << " attacks " << target;
			std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
			this->_energyPoints--;
		}
		else
			displayNotEnoughEnergy("attack");
	}
}

void	Claptrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << this->_name << " dealt " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	std::cout << "Claptrap " << this->_name << " now has " << this->_hitPoints << " life points" << std::endl;
}

void	Claptrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			std::cout << "Claptrap repaired himself with " << amount << " points!" << std::endl;
			this->_hitPoints += amount;
			this->_energyPoints--;
			std::cout << "Claptrap " << this->_name << " now has " << this->_hitPoints << " life points" << std::endl;
		}
		else
			displayNotEnoughEnergy("repair himself");
	}
}
