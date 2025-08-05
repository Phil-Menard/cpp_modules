#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Type Animal constructor called." << std::endl;
}

Animal::Animal(Animal const & copy)
{
	std::cout << "Copy Animal constructor called." << std::endl;
	*this = copy;
}

Animal & Animal::operator=(Animal const & other)
{
	std::cout << "Affectation Animal operator called." << std::endl;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout << std::endl;
}
