#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Type WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copy)
{
	std::cout << "Copy WrongAnimal constructor called." << std::endl;
	*this = copy;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other)
{
	std::cout << "Affectation WrongAnimal operator called." << std::endl;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Grrrrrrr!" << std::endl;
}
