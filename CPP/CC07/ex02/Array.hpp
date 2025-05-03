#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
public:
	Array() : _data(0), _size(0) {}
	Array(unsigned int n) : _data(n ? new T[n] : 0), _size(n) {}
	Array(const Array& other) : _data(other._size ? new T[other._size] : 0), _size(other._size)
	{
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	~Array() { delete[] _data; }

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _data;
			_size = other._size;
			_data = _size ? new T[_size] : 0;
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		return *this;
	}

	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _data[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _data[index];
	}

	unsigned int size() const { return _size; }

	class OutOfBoundsException : public std::exception
	{
	public:
		const char* what() const throw() { return "Index out of bounds"; }
	};

private:
	T* _data;
	unsigned int _size;
};

#endif

