#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void	iter(T* arr, size_t len, Func function)
{
	for(size_t i = 0; i < len; ++i)
		function(arr[i]);
}

void	printInt(const int &x);
void	printStr(const std::string& str);
void	replaceInt(int &x);

#endif