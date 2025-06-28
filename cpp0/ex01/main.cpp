#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook repertoire;
	std::string name = "romain";

	std::cout << repertoire.get_contact(0, name).get_firstName() << std::endl;

	return (0);
}
