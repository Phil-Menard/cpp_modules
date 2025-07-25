#include "Claptrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	Claptrap claptrap("Claptrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	claptrap.attack("Roland");
	claptrap.takeDamage(2);
	claptrap.beRepaired(2);

	//ATTACK UNTIL NO ENERGY LEFT
	for (int i = 0; i < 9; i++)
		claptrap.attack("Roland");

	std::cout << std::endl;
	ScavTrap scavtrap("ScavTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	scavtrap.attack("Roland");
	scavtrap.takeDamage(2);
	scavtrap.beRepaired(2);
	scavtrap.guardGate();

	std::cout << std::endl;
	FragTrap fragtrap("FragTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	fragtrap.attack("Roland");
	fragtrap.takeDamage(2);
	fragtrap.beRepaired(2);
	fragtrap.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
