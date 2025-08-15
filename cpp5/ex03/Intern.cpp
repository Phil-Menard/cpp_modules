#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

Intern & Intern::operator=(Intern const & other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::President(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::Robotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::Shrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	for(size_t i = 0; i < name.size(); i++)
	name[i] = std::tolower(name[i]);

	std::string	formName[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*form[3])(const std::string) = {&Intern::Robotomy, &Intern::President, &Intern::Shrubbery};

	for (size_t i = 0; i < 3; i++)
	{
		if (name == formName[i])
		{
			std::cout << "Intern creates form." << std::endl;
			return (this->*form[i])(target);
		}
	}
	std::cout << "There is no form known under this name" << std::endl;
	return 0;
}
