#include <iostream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	PhoneBook repertoire;
	std::string arg;

	(void) argv;
	if (argc != 1)
		std::cout << "Too many arguments." << std::endl;
	while (arg.compare("EXIT") != 0)
	{
		std::cout << "Enter your command [ADD|SEARCH|EXIT] : ";
		std::cin >> arg;
		int	i = -1;
		while (arg[++i])
			arg[i] = toupper(arg[i]);
		if (arg.compare("ADD") == 0)
			repertoire.add();
		else if (arg.compare("SEARCH") == 0)
			repertoire.search();
	}
	return (0);
}
