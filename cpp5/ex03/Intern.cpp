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

	forms forms[3] = {
		{"robotomy request", &Intern::Robotomy},
		{"presidential pardon", &Intern::President},
		{"shrubbery creation", &Intern::Shrubbery}
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (name == forms[i].formName)
		{
			std::cout << "Intern creates form \"" << name << "\"." << std::endl;
			return (this->*forms[i].func)(target);
		}
	}
	std::cout << "There is no form known under \"" << name << "\"." << std::endl;
	return 0;
}
