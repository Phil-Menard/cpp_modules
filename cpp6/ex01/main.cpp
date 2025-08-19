#include <iostream>
#include <iomanip>
#include "Serializer.hpp"

int main()
{
	Data d;
	d.val = 42;
	
	uintptr_t a = Serializer::serialize(&d);
	std::cout << a << std::endl;
	Data* b = Serializer::deserialize(a);
	std::cout << b->val << std::endl;

	return 0;
}
