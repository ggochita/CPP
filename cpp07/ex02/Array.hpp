#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T* _arr;
	size_t	_size;
public:
	Array();
	Array(size_t n);
	Array(const Array& copy);
	~Array();

	Array& 		operator=(const Array& other);
	T&			operator[](size_t index);
	const T&	operator[](size_t index) const;

	size_t		size() const;
	
};

#include "Array.tpp"

#endif
