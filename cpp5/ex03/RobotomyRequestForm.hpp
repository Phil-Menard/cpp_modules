#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & other);
		~RobotomyRequestForm();

		virtual void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif