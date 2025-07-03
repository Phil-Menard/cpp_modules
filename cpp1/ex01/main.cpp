#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int		N = 15;

	Zombie *horde = zombieHorde(N, "Marc");
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return 0;
}
