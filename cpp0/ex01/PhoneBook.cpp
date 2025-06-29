#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int	PhoneBook::_get_index() const
{
	return this->_index;
}

void	PhoneBook::_increment_index()
{
	this->_index++;
	if (this->_index > 7)
		this->_index = 0;
	return;
}

static int	check_input(std::string &str)
{
	if (str.empty())
		return 0;

	std::size_t	i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (i == str.length())
		return 0;
	else
		return 1;
}

void	PhoneBook::_display_phonebook() const
{
	std::cout << std::setw(10);
	std::cout << "INDEX" << "|";
	std::cout << std::setw(10);
	std::cout << "FIRST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << "LAST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << "NICK NAME" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (this->_contacts[i].get_firstName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].get_firstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_firstName() << "|";
		if (this->_contacts[i].get_lastName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].get_lastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->_contacts[i].get_lastName() << "|";
		if (this->_contacts[i].get_nickName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].get_nickName().substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << this->_contacts[i].get_nickName() << std::endl;
	}
}

void	PhoneBook::add()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string secret;

	std::cout << "first name : ";
	while (check_input(firstName) == 0)
		std::getline(std::cin, firstName);
	std::cout << "last name : ";
	while (check_input(lastName) == 0)
		std::getline(std::cin, lastName);
	std::cout << "nick name : ";
	while (check_input(nickName) == 0)
		std::getline(std::cin, nickName);
	std::cout << "phone number : ";
	while (check_input(phoneNumber) == 0)
		std::getline(std::cin, phoneNumber);
	std::cout << "darkest secret : ";
	while (check_input(secret) == 0)
		std::getline(std::cin, secret);

	this->_contacts[this->_get_index()].set_contact(firstName, lastName, nickName, phoneNumber, secret);
	this->_increment_index();
	return;
}

void	PhoneBook::search()
{
	std::string	index;

	this->_display_phonebook();
	std::cout << "Input contact index to get informations : ";
	std::cin >> index;
	int j = index.at(0) - '0';
	if (index.size() == 1 && (j >= 0 && j <= 7))
	{
		if (!this->_contacts[j].get_firstName().empty())
			std::cout << "First name : " << this->_contacts[j].get_firstName() << std::endl;
		if (!this->_contacts[j].get_lastName().empty())
			std::cout << "Last Name : " << this->_contacts[j].get_lastName() << std::endl;
		if (!this->_contacts[j].get_nickName().empty())
			std::cout << "Nick name : " << this->_contacts[j].get_nickName() << std::endl;
		if (!this->_contacts[j].get_phoneNumber().empty())
			std::cout << "Phone number : " << this->_contacts[j].get_phoneNumber() << std::endl;
		if (!this->_contacts[j].get_darkestSecret().empty())
			std::cout << "Darkest secret : " << this->_contacts[j].get_darkestSecret() << std::endl;
	}
	else
		std::cout << "Input should only be a number between 0 and 7 included." << std::endl;
	return;
}
