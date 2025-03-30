#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return *this; }

AForm* Intern::creatShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::creatRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::creatPresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string names[3] =
	{
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};
	AForm* (Intern::*creationFuncs[])(const std::string&) const =
	{
		&Intern::creatRobotomy,
		&Intern::creatShrubbery,
		&Intern::creatPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << name << " form created!" << std::endl;
			return (this->*creationFuncs[i])(target);
		}
	}
	std::cout << name << " does not match real form names!" << std::endl;
	return (NULL);

}