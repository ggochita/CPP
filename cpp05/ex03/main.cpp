#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someIntern;
	AForm* form;

	std::cout << "\n--- Creating a real form ---" << std::endl;
	form = someIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	form = someIntern.makeForm("shrubbery creation", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}
	form = someIntern.makeForm("presidential pardon", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\n--- Creating a fake form ---" << std::endl;
	form = someIntern.makeForm("dragon form", "Daenerys");
	if (form)
		delete form;

	return 0;
}
