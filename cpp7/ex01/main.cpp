#include "iter.hpp"

template<typename T>
void printNum(T const & a)
{
	std::cout << a << std::endl;
}

int main()
{
	int arr[] = { 1,2,3,4,99};
	size_t a = 5;
	::iter(arr, a, printNum);

	return 0;
}