#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(Form const & copy);
		Form & operator=(Form const & other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(Bureaucrat bureaucrat);

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

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExec;
};

std::ostream & operator<<(std::ostream & out, const Form & form);

#endif