#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int i);

template <typename T>
typename T::const_iterator easyfind(const T& container, int i);

#include "easyfind.tpp"

#endif
