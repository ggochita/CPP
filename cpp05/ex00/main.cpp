#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		// Default constructor
		Bureaucrat def;
		std::cout << "Default Bureaucrat:\n" << def << std::endl;

		// Custom constructor
		Bureaucrat a("Alice", 2);
		std::cout << "\n" << a << std::endl;

		// Decrement test (grade goes down)
		a.decrementGrade(); // 2 → 3
		std::cout << "After decrement: " << a << std::endl;

		// Increment test (grade goes up)
		a.incrementGrade(); // 3 → 2
		std::cout << "After increment: " << a << std::endl;

		// Assignment operator test
		Bureaucrat b("Bob", 150);
		std::cout << "\n" << b << std::endl;

		b = a;
		std::cout << "After assigning 'a' to 'b':\n" << b << std::endl;

		// Copy constructor test
		Bureaucrat c = b;
		std::cout << "Copy of b (c):\n" << c << std::endl;

		// Self-assignment test
		b = b;

		// Exception test - grade too high
		std::cout << "\nTesting exception: grade too high" << std::endl;
		Bureaucrat d("Danger", 0); // Should throw

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		// Exception test - grade too low
		std::cout << "\nTesting exception: grade too low" << std::endl;
		Bureaucrat e("Error", 151); // Should throw

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << "\n" << std::endl;
	}

	try {
		std::cout << "Exception test - decrement below 150" << std::endl;
		Bureaucrat f("Frank", 150);
		f.decrementGrade(); // Should throw
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << "\n" << std::endl;
	}

	try {
		std::cout << "Exception test - increment above 1" << std::endl;
		Bureaucrat g("Grace", 1);
		g.incrementGrade(); // Should throw
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
