#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const & copy)
{
	std::cout << "Copy Cat constructor called." << std::endl;
	*this = copy;
}

Cat & Cat::operator=(Cat const & other)
{
	std::cout << "Affectation Cat operator called." << std::endl;
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Miaouuuuuuu" << std::endl;
}
