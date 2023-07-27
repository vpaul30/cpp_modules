#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	it = find(container.begin(), container.end(), value);
	if (it == container.end())
		return container.end();
	return it;
}

#endif