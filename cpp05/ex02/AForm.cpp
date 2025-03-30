#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("default-form"), _isSigned(false),
				_gradeToSign(5), _gradeToExec(2)
{
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExec)
:	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
:	_name(copy._name),
	_isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign),
	_gradeToExec(copy._gradeToExec)
{
}

AForm::~AForm()
{
}

const std::string& AForm::getName(void) const
{
	return (_name);
}

bool AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& bob)
{
	if (bob.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	if (this->_isSigned)
		throw AlreadySignedException();
	this->_isSigned = true;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form  grade is too HIGH!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form  grade is too LOW!");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("Form  is already SIGNED!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not SIGNED!");
}


std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << "Form-name: " << rhs.getName() << std::endl
	<< "Form-Signed?: " << rhs.getIsSigned() << std::endl
	<< "Form-To-Sign: " << rhs.getGradeToSign() << std::endl
	<< "Form-To-Exec: " << rhs.getGradeToExec() << std::endl;
	return os;
}