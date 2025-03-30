#include "Serializer.hpp"
#include <iostream>

int main() {
	Data original;
	original.x = 42;
	original.c = 'A';
	original.str = "Hello, world!";

	std::cout << "--- Original Data ---" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "x: " << original.x << std::endl;
	std::cout << "c: " << original.c << std::endl;
	std::cout << "str: " << original.str << std::endl;

	std::cout << "\n--- Serialization ---" << std::endl;
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Raw (uintptr_t): " << raw << std::endl;

	std::cout << "\n--- Deserialization ---" << std::endl;
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored Address: " << restored << std::endl;
	std::cout << "x: " << restored->x << std::endl;
	std::cout << "c: " << restored->c << std::endl;
	std::cout << "str: " << restored->str << std::endl;

	std::cout << "\n--- Comparison ---" << std::endl;
	std::cout << "Same pointer? " << (restored == &original ? "Yes" : "No") << std::endl;

	return 0;
}
