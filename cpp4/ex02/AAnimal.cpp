#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Default AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Type AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const & copy)
{
	std::cout << "Copy AAnimal constructor called." << std::endl;
	*this = copy;
}

AAnimal & AAnimal::operator=(AAnimal const & other)
{
	std::cout << "Affectation AAnimal operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}

void	AAnimal::makeSound() const
{
	std::cout << std::endl;
}
