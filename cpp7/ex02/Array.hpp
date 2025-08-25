#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>


template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & copy);
		Array & operator=(Array const & other);
		~Array();

		T & operator[](unsigned int n);
		T const & operator[](unsigned int n) const;
		size_t size() const;

		class OutOfBoundsException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		T* _arr;
		size_t _size;
};

#include "Array.tpp"

#endif