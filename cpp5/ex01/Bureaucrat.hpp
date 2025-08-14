#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Form;
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & copy);
		Bureaucrat & operator=(Bureaucrat const & other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const _name;
		int _grade;
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & name);

#endif