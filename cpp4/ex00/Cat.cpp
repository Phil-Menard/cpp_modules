#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(Cat const & copy)
{
	std::cout << "Copy Cat constructor called." << std::endl;
	*this = copy;
}

Cat & Cat::operator=(Cat const & other)
{
	std::cout << "Affectation Cat operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miaouuuuuuu" << std::endl;
}
