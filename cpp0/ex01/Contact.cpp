#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact()
{
	return;
}

Contact::~Contact()
{
	return;
}

std::string Contact::get_firstName() const
{
	return this->_firstName;
}

std::string Contact::get_lastName() const
{
	return this->_lastName;
}

std::string Contact::get_nickName() const
{
	return this->_nickName;
}

std::string Contact::get_phoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::get_darkestSecret() const
{
	return this->_darkestSecret;
}

void	Contact::set_contact(std::string firstName, std::string lastName, std::string nickName,
			std::string phoneNumber, std::string secret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = secret;
	return;
}
