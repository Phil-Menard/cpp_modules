#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T array[], size_t const & length, void(*f)(T &))
{
	// std::cout << "called normal version" << std::endl;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void iter(T const array[], size_t const & length, void(*f)(T const &))
{
	// std::cout << "called const version" << std::endl;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}



#endif