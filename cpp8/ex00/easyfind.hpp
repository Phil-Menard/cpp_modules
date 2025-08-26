#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class OccurenceNotFound : public std::exception
{
	virtual const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T & container, int n);

template<typename T>
typename T::const_iterator easyfind(T const & container, int n);

#include "easyfind.tpp"

#endif