#include "Claptrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	Claptrap claptrap("Claptrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	claptrap.attack("Roland");
	claptrap.takeDamage(2);
	claptrap.beRepaired(2);

	//DON'T HAVE ENOUGH ENERGY ON LAST ATTACK
	for (int i = 0; i < 9; i++)
		claptrap.attack("Roland");

	std::cout << std::endl;
	ScavTrap scavtrap("ScavTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	scavtrap.attack("Roland");
	scavtrap.takeDamage(2);
	scavtrap.beRepaired(2);
	//DON'T HAVE ENOUGH ENERGY ON LAST ATTACK
	for (int i = 0; i < 9; i++)
		scavtrap.attack("Roland");
	scavtrap.guardGate();

	std::cout << std::endl;
	return 0;
}
