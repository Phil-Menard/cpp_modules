#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & copy);
		Intern & operator=(Intern const & other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);
		AForm* President(const std::string target);
		AForm* Robotomy(const std::string target);
		AForm* Shrubbery(const std::string target);

		struct forms
		{
			std::string formName;
			AForm* (Intern::*func)(const std::string);
		};
};

#endif