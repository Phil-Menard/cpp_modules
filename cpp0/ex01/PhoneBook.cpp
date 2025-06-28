#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook created" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed" << std::endl;
	return;
}

Contact	PhoneBook::get_contact(int index, std::string str)
{
	this->contacts[index].set_firstName(str);
	return (this->contacts[index]);
}
