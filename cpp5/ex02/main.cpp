#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//CAN EXECUTE THE FORM
	try
	{
		Bureaucrat guy("Guy", 2);
		PresidentialPardonForm form("Zizou");
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
		guy.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << std::endl;

	return 0;
}
