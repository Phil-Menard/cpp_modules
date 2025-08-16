#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{	
	Bureaucrat guy("Guy", 1);
	Intern robin;
	AForm* error_form;
	AForm* pardon_form;
	AForm* request_form;
	AForm* creation_form;

	error_form = robin.makeForm("wrong form", "Barbara");
	pardon_form = robin.makeForm("presidential pardon", "Gordon");
	request_form = robin.makeForm("robotomy request", "Mr Freeze");
	creation_form = robin.makeForm("shrubbery creation", "Gotham");

	std::cout << std::endl;
	std::cout << guy << std::endl;
	std::cout << std::endl;

	//WRONG FORM
	if (error_form)
	{
		std::cout << *error_form << std::endl;
		guy.signForm(*error_form);
		std::cout << *error_form << std::endl;
		guy.executeForm(*error_form);
		delete error_form;
	}

	//PRESIDENTIAL PARDON FORM
	if (pardon_form)
	{
		std::cout << *pardon_form << std::endl;
		guy.signForm(*pardon_form);
		std::cout << *pardon_form << std::endl;
		guy.executeForm(*pardon_form);
		delete pardon_form;
	}

	std::cout << "----------------" << std::endl;

	//ROBOTOMY REQUEST FORM
	if (request_form)
	{
		std::cout << *request_form << std::endl;
		guy.signForm(*request_form);
		std::cout << *request_form << std::endl;
		guy.executeForm(*request_form);
		guy.executeForm(*request_form);
		guy.executeForm(*request_form);
		guy.executeForm(*request_form);
		guy.executeForm(*request_form);
		delete request_form;
	}

	std::cout << "----------------" << std::endl;

	////SHRUBBERY CREATION FORM
	if (creation_form)
	{
		std::cout << *creation_form << std::endl;
		guy.signForm(*creation_form);
		std::cout << *creation_form << std::endl;
		guy.executeForm(*creation_form);
		delete creation_form;
	}

	return 0;
}
