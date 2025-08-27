#include "easyfind.hpp"

int main()
{
	//VECTOR
	try
	{
		std::vector<int>a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		a.push_back(40);
		a.push_back(50);
		std::vector<int>::iterator it = easyfind(a, 50);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-------------------" << std::endl;

	//CONST VECTOR
	try
	{
		int arr[] = {1,2,3,4,5};
		const std::vector<int> a(arr, arr + 5);
		std::vector<int>::const_iterator it = easyfind(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------------------" << std::endl;

	//LIST
	try
	{
		std::list<int>a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);
		std::list<int>::iterator it = easyfind(a, 1);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-------------------" << std::endl;

	//CONST LIST
	try
	{
		int arr[] = {1,2,3,4,5};
		const std::list<int> a(arr, arr + 5);
		std::list<int>::const_iterator it = easyfind(a, -2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
