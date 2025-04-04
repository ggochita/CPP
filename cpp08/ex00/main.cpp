#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
{
	// Vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	int cant = 42;

	std::cout << "--- Testing std::vector ---" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
		easyfind(vec, cant); // Should throw
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << " " << cant << std::endl;
	}
}
{
	// Deque
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(10);
	deq.push_back(15);
	int	cant = 99;

	std::cout << "\n--- Testing std::deque ---" << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 10);
		std::cout << "Found: " << *it << std::endl;
		easyfind(deq, 99); // Should throw
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << " " << cant << std::endl;
	}
}
{
	// List
	std::list<int> lst;
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	int cant = -1;

	std::cout << "\n--- Testing std::list ---" << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 9);
		std::cout << "Found: " << *it << std::endl;
		easyfind(lst, -1); // Should throw
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << " " << cant << std::endl;
	}

	return 0;
}
}
