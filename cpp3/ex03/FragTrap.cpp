#include "FragTrap.hpp"

FragTrap::FragTrap()
{

}

FragTrap::FragTrap(std::string name) : Claptrap(name, FragTrap::_hitPoints, 100, FragTrap::_attackDamage)
{
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Oh yeah! Give me five guys!" << std::endl;
}
