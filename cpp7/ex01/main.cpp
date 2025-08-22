#include "iter.hpp"
#include <iomanip>

template<typename T>
void printElement(T const & a)
{
	std::cout << std::fixed << std::setprecision(1) << a << std::endl;
}

template<typename T>
void incrementValue(T & a)
{
	a++;
}

template<typename T>
void doubleValue(T & a)
{
	a*=2;
}

template<typename T>
void divideValue(T & a)
{
	a/=2;
}

template<typename T>
void addStr(T & a)
{
	a += (" " + a);
}

int main()
{
	//int array
	{
		int arr[] = {1, 2, 3, 4, 99};
		size_t a = 5;
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, incrementValue);
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, doubleValue);
		::iter(arr, a, printElement);
	}

	std::cout << "----------------------------" << std::endl;

	//float array
	{
		float arr[] = {1.0f, 2.0f, 3.0f, 4.0f, 99.0f};
		size_t a = 5;
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, incrementValue);
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, divideValue);
		::iter(arr, a, printElement);
	}

	std::cout << "----------------------------" << std::endl;

	//char array
	{
		char arr[] = {'a', 'b', 'c', 'd', 'e'};
		size_t a = 5;
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, incrementValue);
		::iter(arr, a, printElement);
	}

	std::cout << "----------------------------" << std::endl;

	//string array
	{
		std::string arr[] = {"the", "cake", "is", "a", "lie"};
		size_t a = 5;
		::iter(arr, a, printElement);
		std::cout << std::endl;
		::iter(arr, a, addStr);
		::iter(arr, a, printElement);
	}

	return 0;
}
