#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack& copy);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& other);

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif
