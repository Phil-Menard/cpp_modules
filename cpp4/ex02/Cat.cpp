#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->brain = new Brain();
}

Cat::Cat(Cat const & copy)
{
	std::cout << "Copy Cat constructor called." << std::endl;
	this->brain = NULL;
	*this = copy;
}

Cat & Cat::operator=(Cat const & other)
{
	std::cout << "Affectation Cat operator called." << std::endl;
	if (this != &other)
		this->type = other.type;

	if (this->brain)
		delete this->brain;

	this->brain = new Brain(*other.brain);
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
