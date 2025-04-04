#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        return it;
    else
        throw std::runtime_error("can't find value");
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int i)
{
    typename T::const_iterator cit;

    cit = std::find(container.begin(), container.end(), i);
    if (cit != container.end())
        return cit;
    else
        throw std::runtime_error("can't find value");
}
