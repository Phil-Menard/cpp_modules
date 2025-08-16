#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//CAN SIGN THE FORM
	try
	{
		Bureaucrat guy("Guy", 50);
		Form form("24E", 60, 50);
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << std::endl;

	//CAN NOT SIGN THE FORM
	try
	{
		Bureaucrat guy("Guy", 50);
		Form form("42C", 20, 50);
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << std::endl;

	//CAN SIGN AFTER INCREASING GRADE
	try
	{
		Bureaucrat guy("Guy", 22);
		Form form("42C", 20, 50);
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.incrementGrade();
		guy.incrementGrade();
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << std::endl;

	//IMPOSSIBLE TO SIGN - TOO HIGH
	try
	{
		Bureaucrat guy("Guy", 50);
		Form form("42C", 0, 50);
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << std::endl;

	//IMPOSSIBLE TO SIGN - TOO LOW
	try
	{
		Bureaucrat guy("Guy", 50);
		Form form("42C", 160, 50);
		std::cout << form << std::endl;
		std::cout << guy << std::endl;
		guy.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
