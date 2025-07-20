#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : Claptrap(name + "_clap_name", FragTrap::_hitPoints, ScavTrap::_energyPoints, FragTrap::_attackDamage)
{
    this->_name = name;
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
