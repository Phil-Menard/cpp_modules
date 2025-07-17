#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : Claptrap(name, 100, 100, 30)
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
