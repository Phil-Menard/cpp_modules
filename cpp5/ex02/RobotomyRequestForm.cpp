#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("Someone")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm("Robotomy Request", 72, 45)
{
	*this = copy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::checkBeforeExecution(executor);
		int random;
		random = rand() % 2;
		if (random == 0)
			std::cout << this->_target << " has been robotomized." << std::endl;
		else
			std::cout << "The robotomy has failed." << std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
