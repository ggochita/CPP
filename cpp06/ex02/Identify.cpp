#include "Identify.hpp"


Base::Base() {}

Base::~Base() {}

Base*	generate(void) // 33.3% chance 
{
	int r = std::rand();

	if (r % 3 == 0)
		return new A;
	else if (r % 3 == 1)
		return new B;
	return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "it is type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "it is type: B" << std::endl;
	else
		std::cout << "it is type: C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& aType = dynamic_cast<A&>(p);
		(void)aType;
		std::cout << "it is type: A" << std::endl;
	}
	catch (...) {}

	try
	{
		B& bType = dynamic_cast<B&>(p);
		(void)bType;
		std::cout << "it is type: B" << std::endl;
	}
	catch (...) {}

	try
	{
		C& cType = dynamic_cast<C&>(p);
		(void)cType;
		std::cout << "it is type: C" << std::endl;
	}
	catch (...) {}
}