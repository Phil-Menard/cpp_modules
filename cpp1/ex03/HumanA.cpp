#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _type(type)
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_type.getType() << std::endl;
}
