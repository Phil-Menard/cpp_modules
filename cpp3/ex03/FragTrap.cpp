#include "FragTrap.hpp"

int FragTrap::_hitPoints = 100;
unsigned int FragTrap::_attackDamage = 42;

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : Claptrap(name, FragTrap::_hitPoints, 100, FragTrap::_attackDamage)
{
	std::cout << "FragTrap name constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : Claptrap(copy)
{
	std::cout << "Copy FragTrap constructor called." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
	std::cout << "Affectation FragTrap constructor called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Oh yeah! Give me five guys!" << std::endl;
}
