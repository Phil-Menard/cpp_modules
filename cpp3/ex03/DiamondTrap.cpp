#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", FragTrap::_hitPoints, ScavTrap::_defaultEnergyPoints, FragTrap::_attackDamage)
{
	std::cout << "DiamondTrap name constructor called." << std::endl;
	this->_name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "Copy DiamondTrap constructor called." << std::endl;
	this->_name = copy._name;
	this->_energyPoints = ScavTrap::_defaultEnergyPoints;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other)
{
	std::cout << "Affectation DiamondTrap constructor called." << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My real name is " << this->_name << ". ";
	std::cout << "My ClapTrap name is " << ClapTrap::getName() << "." << std::endl;
}
