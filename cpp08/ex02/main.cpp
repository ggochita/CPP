#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

void testMutantStack() {
	std::cout << "--- MutantStack Test ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(30);
	mstack.push(40);
	mstack.push(50);
	mstack.push(60);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void testList() {
	std::cout << "--- std::list Test ---" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	lst.push_back(60);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << "PUSHED: 5 then 17" << std::endl;
    
    std::cout << "TOP: " << mstack.top() << std::endl;
    
    std::cout << "POPED: " << mstack.top() << std::endl;
    mstack.pop();
    
    std::cout << "SIZE: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "PUSHED: 3 then 5, 737, 0" << std::endl;

    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "Iterator use:" << std::endl;
    while (it != ite)
    {
        std::cout << " --" << *it << std::endl;
        ++it;
    }

    std::cout << "\n\n" << "--TEST COMPARISON OF LIST AND MUTANTSTACK--" << "\n\n";
    testMutantStack();
    testList();

    return 0;
}
