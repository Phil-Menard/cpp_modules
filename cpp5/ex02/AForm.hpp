#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec);
		AForm(AForm const & copy);
		AForm & operator=(AForm const & other);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(Bureaucrat bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeToSignTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeToSignTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeToExecTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeToExecTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedBeforeExecException : public std::exception
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

std::ostream & operator<<(std::ostream & out, const AForm & form);

#endif