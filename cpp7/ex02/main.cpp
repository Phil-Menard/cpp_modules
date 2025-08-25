#include "Array.hpp"
#include <math.h>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

/* int main()
{
	{
		Array<int> a;
		if (a.size() == 0)
			std::cout << "Array is empty" << std::endl;
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	{
		Array<int> a(10);
		if (a.size() == 0)
			std::cout << "Array is empty" << std::endl;
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = i * 2;
			std::cout << a[i] << std::endl;
		}
	}

	std::cout << "------------------------" << std::endl;

	{
		Array<char> a(10);
		if (a.size() == 0)
		std::cout << "Array is empty" << std::endl;
		Array<char> b = a;
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = 'A' + i;
			std::cout << a[i] << std::endl;
		}
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	{
		const std::string s = "voila";
		Array<char> a(5);
		if (a.size() == 0)
			std::cout << "Array is empty" << std::endl;
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = s[i];
			std::cout << a[i] << std::endl;
		}
		const Array<char> b(a);
		for (size_t i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;
		const Array<char> c(b);
		for (size_t i = 0; i < c.size(); i++)
			std::cout << c[i] << std::endl;
	}

	return 0;
} */
