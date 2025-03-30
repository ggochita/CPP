#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(0)); // 🔑 Seed randomness for Robotomy

	try {
		Bureaucrat high("Alice", 1);
		Bureaucrat mid("Bob", 50);
		Bureaucrat low("Joe", 150);

		ShrubberyCreationForm shrub("Garden");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Ford Prefect");

		std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
		low.signForm(shrub);      // too low to sign
		mid.signForm(shrub);      // should succeed
		low.executeForm(shrub);   // too low to execute
		mid.executeForm(shrub);   // should succeed

		std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
		robo.beSigned(high);          // high signs directly
		mid.executeForm(robo);        // should fail (exec grade too low)
		high.executeForm(robo);       // should work, 50% success

		std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
		pardon.beSigned(high);        // high signs
		mid.executeForm(pardon);      // should fail
		high.executeForm(pardon);     // should succeed

		std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
		ShrubberyCreationForm badForm("UnsignedTest");
		high.executeForm(badForm);    // should throw NotSignedException
	}
	catch (std::exception &e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}

	return 0;
}
