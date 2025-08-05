#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
	this->brain = new Brain();
}

Dog::Dog(Dog const & copy)
{
	std::cout << "Copy Dog constructor called." << std::endl;
	*this = copy;
}

Dog & Dog::operator=(Dog const & other)
{
	std::cout << "Affectation Dog operator called." << std::endl;
	this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "Wouaf wouaf!" << std::endl;
}
