#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "---[ Valid Form and Bureaucrat ]---" << std::endl;
	Bureaucrat bob("Bob", 42);
	Form formA("FormA", 50, 25);

	std::cout << formA << std::endl;
	bob.signForm(formA); // should succeed
	std::cout << formA << std::endl;

	std::cout << "\n---[ Form already signed ]---" << std::endl;
	bob.signForm(formA); // already signed message 	

	std::cout << "\n---[ Bureaucrat with too low grade ]---" << std::endl;
	Bureaucrat joe("Joe", 100);
	Form formB("FormB", 80, 30);
	std::cout << formB << std::endl;
	joe.signForm(formB); // should fail

	std::cout << "\n---[ Exception on invalid form grade ]---" << std::endl;
	try {
		Form badForm("BadForm", 0, 10); // grade too high (invalid)
	} catch (std::exception& e) {
		std::cout << "Caught exception while creating form: " << e.what() << std::endl;
	}

	try {
		Form badForm2("BadForm2", 151, 10); // grade too low (invalid)
	} catch (std::exception& e) {
		std::cout << "Caught exception while creating form: " << e.what() << std::endl;
	}

	std::cout << "\n---[ Operator<< Overload Check ]---" << std::endl;
	Bureaucrat alice("Alice", 1);
	Form eliteForm("EliteForm", 1, 1);
	std::cout << alice << std::endl;
	std::cout << eliteForm << std::endl;

	std::cout << "\n---[ Alice signs EliteForm ]---" << std::endl;
	alice.signForm(eliteForm);
	std::cout << eliteForm << std::endl;

	return 0;
}
