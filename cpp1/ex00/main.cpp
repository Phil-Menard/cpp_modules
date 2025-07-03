#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	//	ZOMBIE STACK
	randomChump("alan");

	//	ZOMBIE HEAP
	Zombie *zombie = newZombie("jean");
	zombie->announce();

	//	ZOMBIE STACK
	randomChump("gustave");

	//	FREE ZOMBIE HEAP
	delete zombie;

	return 0;
}
