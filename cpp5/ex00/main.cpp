#include "Bureaucrat.hpp"

int main()
{
	//GRADE TOO LOW
	try
	{
		Bureaucrat touLo("Toulo", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "----------------------" << std::endl;

	//GRADE TOO HIGH
	try
	{
		Bureaucrat touAie("TouAie", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------" << std::endl;

	//GRADE OK -- INCREMENT GRADE
	try
	{
		Bureaucrat incre("Incre", 50);
		std::cout << incre << std::endl;
		incre.incrementGrade();
		std::cout << incre << std::endl;
		incre.incrementGrade();
		std::cout << incre << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "----------------------" << std::endl;

	//GRADE OK -- DECREMENT GRADE
	try
	{
		Bureaucrat decre("Decre", 100);
		std::cout << decre << std::endl;
		decre.decrementGrade();
		std::cout << decre << std::endl;
		decre.decrementGrade();
		std::cout << decre << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------" << std::endl;

	//GRADE TOO LOW BY INCREMENTING GRADE
	try
	{
		Bureaucrat incre("Incre", 2);
		std::cout << incre << std::endl;
		incre.incrementGrade();
		std::cout << incre << std::endl;
		incre.incrementGrade();
		std::cout << incre << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "----------------------" << std::endl;

	//GRADE TOO HIGH BY DECREMENTING GRADE 
	try
	{
		Bureaucrat decre("Decre", 149);
		std::cout << decre << std::endl;
		decre.decrementGrade();
		std::cout << decre << std::endl;
		decre.decrementGrade();
		std::cout << decre << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
