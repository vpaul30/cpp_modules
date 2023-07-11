#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	unsigned int _size;
	T *_array;

public:
	Array() : _size(0)
	{
		std::cout << "Array default constructor called.\n";
		_array = new T[_size];
	}
	Array(unsigned int n) : _size(n)
	{
		std::cout << "Array constructor called.\n";
		_array = new T[_size];
	}
	Array(const Array &other)
	{
		std::cout << "Array copy constructor called.\n";
		_array = NULL;
		*this = other;
	}
	~Array()
	{
		std::cout << "Array destructor called.\n";
		delete[] _array;
	}

	Array &operator=(const Array &other)
	{
		std::cout << "Array assignment operator called.\n";
		if (_array)
			delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < other._size; i++)
			_array[i] = other._array[i];
		return *this;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::exception();
		return _array[index];
	}

	unsigned int size() const
	{
		return _size;
	}

};

#endif