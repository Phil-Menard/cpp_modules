#include <iostream>

int	main()
{
	std::string	var = "HI THIS IS BRAIN";

	std::string	*stringPTR = &var;
	std::string	&stringREF = var;

	//	MEMORY ADRESSES
	std::cout << "memory address of the string variable : " << &var << std::endl;
	std::cout << "memory address held by stringPTR :      " << &stringPTR << std::endl;
	std::cout << "memory address held by stringREF :      " << &stringREF << std::endl;

	std::cout << std::endl;

	//	VARIABLES VALUES
	std::cout << "value of the string variable :       " << var << std::endl;
	std::cout << "value pointed to by stringPTR :      " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF :      " << stringREF << std::endl;

	return 0;
}
