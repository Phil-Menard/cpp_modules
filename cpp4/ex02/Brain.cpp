#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called." << std::endl;
}

Brain::Brain(Brain const & copy)
{
	std::cout << "Copy Brain constructor called." << std::endl;
	*this = copy;
}

Brain & Brain::operator=(Brain const & other)
{
	std::cout << "Affectation Brain operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}
