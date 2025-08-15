#include "AForm.hpp"

AForm::AForm() : _name("default") ,_isSigned(false), _gradeToSign(100), _gradeToExec(100)
{}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExec) :
_name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->getGradeToSign() <= 0)
		throw AForm::GradeToSignTooHighException();
	else if (this->_gradeToSign > 150)
		throw AForm::GradeToSignTooLowException();
}

AForm::AForm(AForm const & copy) : _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
}

AForm & AForm::operator=(AForm const & other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	else if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw AForm::GradeToSignTooLowException();
}

void AForm::checkBeforeExecution(Bureaucrat const & executor) const
{
	if (this->getIsSigned())
	{
		if (this->getGradeToExec() <= executor.getGrade())
			throw AForm::GradeToExecTooLowException();
	}
	else
		throw AForm::NotSignedBeforeExecException();
}

const char* AForm::GradeToSignTooHighException::what() const throw()
{
	return "Grade required to sign the form is too high.";
}

const char* AForm::GradeToSignTooLowException::what() const throw()
{
	return "Grade required to sign the form is too low.";
}

const char* AForm::GradeToExecTooHighException::what() const throw()
{
	return "Grade required to execute the form is too high.";
}

const char* AForm::GradeToExecTooLowException::what() const throw()
{
	return "Grade required to execute the form is too low.";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "The form has already been signed.";
}

const char* AForm::NotSignedBeforeExecException::what() const throw()
{
	return "The form needs to be signed to be able to execute it.";
}

std::ostream & operator<<(std::ostream & out, AForm const & Aform)
{
	out << "Form under name '" << Aform.getName() << "' is ";
	if (Aform.getIsSigned())
		out << "signed. A grade of " << Aform.getGradeToExec() << " is required to execute it.";
	else
	{
		out << "not signed. A grade of " << Aform.getGradeToSign() << " is required to sign it. ";
		out << "A grade of " << Aform.getGradeToExec() << " is required to execute it.";
	}
	return out;
}
