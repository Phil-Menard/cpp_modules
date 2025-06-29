#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public :
	PhoneBook(void);
	~PhoneBook(void);
	void	add();
	void	search();

private:
	Contact _contacts[8];
	int		_index;
	int		_get_index() const;
	void	_increment_index();
	void	_display_phonebook() const;
};

#endif