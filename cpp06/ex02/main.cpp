#include "Identify.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));  // seed randomness

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "---[ Test " << i + 1 << " ]---" << std::endl;

		Base* random = generate();

		std::cout << "Using pointer: ";
		identify(random);

		std::cout << "Using reference: ";
		identify(*random);

		delete random;
		std::cout << std::endl;
	}

	return 0;
}
