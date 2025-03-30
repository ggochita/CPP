#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executer.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::cout << "* DRRRRRRRRZZZZZZZZZZZT *" << std::endl;

	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << this->_target << " robotomy failed!" << std::endl;
}