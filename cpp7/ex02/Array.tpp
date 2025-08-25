#include "Array.hpp"

template<typename T>
Array<T>::Array() : _arr(0), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n)
{}

template<typename T>
Array<T>::Array(Array const & copy) : _arr(new T[copy._size]()), _size(copy._size)
{
	for (size_t i = 0; i < this->_size; i++)
		this->_arr[i] = copy._arr[i];
}

template<typename T>
Array<T> & Array<T>::operator=(Array const & other)
{
	this->_size = other._size;
	if (this != &other)
	{
		if (this->_arr)
			delete [] this->_arr;
		this->_arr = new T[this->_size];
		for (size_t i = 0; i < other._size; i++)
		{
			this->_arr[i] = other._arr[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_arr;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Out of bounds.";
}

template<typename T>
T & Array<T>::operator[](unsigned int n)
{
	if (n < this->_size)
		return this->_arr[n];
	else
		throw OutOfBoundsException();
}

template<typename T>
T const & Array<T>::operator[](unsigned int n) const
{
	if (n < this->_size)
		return this->_arr[n];
	else
		throw OutOfBoundsException();
}

template<typename T>
size_t Array<T>::size() const
{
	return this->_size;
}