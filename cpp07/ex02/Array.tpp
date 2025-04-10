#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(size_t n) : _arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>::Array(const Array& copy) : _arr(NULL), _size(copy._size)
{
	if (_size > 0)
	{
		_arr = new T[_size];
		for(size_t i = 0; i < _size; ++i)
			_arr[i] = copy._arr[i];
	}
}

template <typename T>
Array<T>&		Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _arr;
		_size = other._size;
		_arr = (_size > 0) ? new T[_size] : NULL;
		for (size_t i = 0; i < _size; ++i)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T&			Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _arr[index];
}

template <typename T>
size_t		Array<T>::size() const
{
	return _size;
}
