#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : Claptrap(name + "_clap_name", FragTrap::_hitPoints, ScavTrap::_energyPoints, FragTrap::_attackDamage)
{
    std::cout << "DiamondTrap name constructor called." << std::endl;
    this->_name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : Claptrap(copy), ScavTrap(copy), FragTrap(copy)
{
    std::cout << "Copy DiamondTrap constructor called." << std::endl;
    this->_name = copy._name;
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
    std::cout << "My ClapTrap name is " << Claptrap::getName() << "." << std::endl;
}
