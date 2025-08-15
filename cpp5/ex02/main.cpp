#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	//CAN EXECUTE ALL THE FORMS
	{
		Bureaucrat guy("Guy", 1);
		PresidentialPardonForm pardon_form("Superman");
		RobotomyRequestForm request_form("Batman");
		ShrubberyCreationForm creation_form("Batcave1");
		
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << guy << std::endl;
		std::cout << std::endl;
		
		guy.signForm(pardon_form);
		guy.signForm(request_form);
		guy.signForm(creation_form);
		
		std::cout << std::endl;
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << std::endl;
		
		guy.executeForm(pardon_form);
		std::cout << std::endl;
		
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		std::cout << std::endl;
		
		guy.executeForm(creation_form);
	}

	std::cout << "--------------" << std::endl;

	//CANNOT EXECUTE ANY FORM
	{

		Bureaucrat guy("Guy", 150);
		PresidentialPardonForm pardon_form("Superman");
		RobotomyRequestForm request_form("Batman");
		ShrubberyCreationForm creation_form("Batcave2");
		
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << guy << std::endl;
		std::cout << std::endl;
		
		guy.signForm(pardon_form);
		guy.signForm(request_form);
		guy.signForm(creation_form);
		
		std::cout << std::endl;
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << std::endl;

		guy.executeForm(pardon_form);
		std::cout << std::endl;
		
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		std::cout << std::endl;
		
		guy.executeForm(creation_form);
	}

	std::cout << "--------------" << std::endl;

	//CAN ONLY EXECUTE ONE FORM
	{

		Bureaucrat guy("Guy", 100);
		PresidentialPardonForm pardon_form("Superman");
		RobotomyRequestForm request_form("Batman");
		ShrubberyCreationForm creation_form("Batcave3");
		
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << guy << std::endl;
		std::cout << std::endl;
		
		guy.signForm(pardon_form);
		guy.signForm(request_form);
		guy.signForm(creation_form);
		
		std::cout << std::endl;
		std::cout << pardon_form << std::endl;
		std::cout << request_form << std::endl;
		std::cout << creation_form << std::endl;
		std::cout << std::endl;
		
		guy.executeForm(pardon_form);
		std::cout << std::endl;

		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		guy.executeForm(request_form);
		std::cout << std::endl;
		
		guy.executeForm(creation_form);
	
	}

	return 0;
}
