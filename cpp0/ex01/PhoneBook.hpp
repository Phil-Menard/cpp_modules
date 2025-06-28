#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public :
	PhoneBook(void);
	~PhoneBook(void);
	Contact	get_contact(int index, std::string str);

private:
	Contact contacts[8];
};

#endif