#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(time(NULL));

	std::cout << "--- Basic Test ---" << std::endl;
	Span sp(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

		sp.addNumber(99); // Should throw
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Large Range Fill Test ---" << std::endl;
	try {
		Span bigSpan(10000);
		std::vector<int> data;

		for (int i = 0; i < 10000; ++i)
			data.push_back(std::rand());

		bigSpan.addRange(data.begin(), data.end());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
