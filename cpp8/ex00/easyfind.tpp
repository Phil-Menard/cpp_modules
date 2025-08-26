#include "easyfind.hpp"

const char* ::OccurenceNotFound::what() const throw()
{
	return "No occurence has been found.";
}

template<typename T>
typename T::iterator easyfind(T & container, int n)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), n);
	if (it != container.end())
		return it;
	else
		throw OccurenceNotFound();
}

template<typename T>
typename T::const_iterator easyfind(T const & container, int n)
{
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), n);
	if (it != container.end())
		return it;
	else
		throw OccurenceNotFound();
}
