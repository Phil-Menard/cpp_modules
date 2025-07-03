#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_type->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon type)
{
	this->_type = &type;
}