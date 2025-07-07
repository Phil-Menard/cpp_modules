#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Only 1 parameter is allowed." << std::endl;
		return 1;
	}

	Harl harl;
	std::string arg = argv[1];

	harl.complain(arg);

	return 0;
}