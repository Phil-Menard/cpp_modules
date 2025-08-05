#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap ClapTrap("ClapTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	ClapTrap.displayEnergy();
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
	DiamondTrap diamondtrap("DiamondTrap");
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	diamondtrap.displayEnergy();
	diamondtrap.attack("Roland");
	diamondtrap.takeDamage(2);
	diamondtrap.beRepaired(2);
	diamondtrap.whoAmI();
	diamondtrap.displayEnergy();

	std::cout << std::endl;
	DiamondTrap diamondtrap2(diamondtrap);
	std::cout << std::endl;

	//USE OF MANDATORY FUNCTIONS
	diamondtrap2.displayEnergy();
	diamondtrap2.attack("Roland");
	diamondtrap2.takeDamage(2);
	diamondtrap2.beRepaired(2);
	diamondtrap2.whoAmI();
	diamondtrap2.displayEnergy();

	std::cout << std::endl;
	return 0;
}
