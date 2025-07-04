#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
public:
	Contact();
	~Contact();

	std::string	get_firstName() const;
	std::string	get_lastName() const;
	std::string	get_nickName() const;
	std::string	get_phoneNumber() const;
	std::string	get_darkestSecret() const;

	void	set_contact(std::string firstName, std::string lastName, std::string nickName,
			std::string phoneNumber, std::string secret);

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif