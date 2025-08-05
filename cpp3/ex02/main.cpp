#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap ClapTrap("ClapTrap");
	std::cout << std::endl;

	ClapTrap.displayEnergy();
	//USE OF MANDATORY FUNCTIONS
	ClapTrap.attack("Roland");
	ClapTrap.takeDamage(2);
	ClapTrap.beRepaired(2);

	//ATTACK UNTIL NO ENERGY LEFT
	for (int i = 0; i < 9; i++)
		ClapTrap.attack("Roland");
	ClapTrap.displayEnergy();

	std::cout << std::endl;
	ScavTrap scavtrap("ScavTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	scavtrap.displayEnergy();
	scavtrap.attack("Roland");
	scavtrap.takeDamage(2);
	scavtrap.beRepaired(2);
	scavtrap.guardGate();
	scavtrap.displayEnergy();

	std::cout << std::endl;
	FragTrap fragtrap("FragTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	fragtrap.displayEnergy();
	fragtrap.attack("Roland");
	fragtrap.takeDamage(2);
	fragtrap.beRepaired(2);
	fragtrap.highFivesGuys();
	fragtrap.displayEnergy();

	std::cout << std::endl;
	return 0;
}
