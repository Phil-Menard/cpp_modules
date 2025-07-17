#include "Claptrap.hpp"

int main()
{
	Claptrap claptrap("Claptrap");

	//USE OF MANDATORY FUNCTIONS
	claptrap.attack("Roland");
	claptrap.takeDamage(2);
	claptrap.beRepaired(2);

	//DON'T HAVE ENOUGH ENERGY ON LAST ATTACK
	for (int i = 0; i < 9; i++)
		claptrap.attack("Roland");

	return 0;
}
