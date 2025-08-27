#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const & copy) : std::stack<T>(copy)
{}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::citerator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::citerator MutantStack<T>::end() const
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::riterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::riterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::criterator MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::criterator MutantStack<T>::rend() const
{
	return this->c.rend();
}
