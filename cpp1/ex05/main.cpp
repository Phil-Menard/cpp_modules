#include <iostream>
#include "Harl.hpp"

int	main()
{
	Harl harl;

	//WORKS
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	//DO NOT WORK
	harl.complain("debug");
	harl.complain("plouf");

	return 0;
}