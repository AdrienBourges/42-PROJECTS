#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void iter(T* array, std::size_t length, void (*f)(T&))
{
	for (std::size_t i = 0; i < length; ++i)
		f(array[i]);
}

template<typename T>
void iter(const T* array, std::size_t length, void (*f)(const T&))
{
	for (std::size_t i = 0; i < length; ++i)
		f(array[i]);
}

#endif

