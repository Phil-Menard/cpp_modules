#include <iostream>
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
	return (this->_firstName);
}

std::string Contact::get_lastName() const
{
	return (this->_lastName);
}

std::string Contact::get_nickName() const
{
	return (this->_nickName);
}

std::string Contact::get_phoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret() const
{
	return (this->_darkestSecret);
}

void Contact::set_firstName(std::string str)
{
	this->_firstName = str;
	return;
}

void Contact::set_lastName(std::string str)
{
	this->_lastName = str;
	return;
}

void Contact::set_nickName(std::string str)
{
	this->_nickName = str;
	return;
}

void Contact::set_phoneNumber(std::string str)
{
	this->_phoneNumber = str;
	return;
}

void Contact::set_darkestSecret(std::string str)
{
	this->_darkestSecret = str;
	return;
}
