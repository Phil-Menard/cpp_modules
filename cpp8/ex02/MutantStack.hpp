#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const & copy);
		MutantStack & operator=(MutantStack const & other);
		~MutantStack();

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator citerator;
		typedef typename std::deque<T>::reverse_iterator riterator;
		typedef typename std::deque<T>::const_reverse_iterator criterator;

		iterator begin();
		iterator end();
		citerator begin() const;
		citerator end() const;
		riterator rbegin();
		riterator rend();
		criterator rbegin() const;
		criterator rend() const;
};

#include "MutantStack.tpp"

#endif