#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *arr, unsigned int arr_len, void (*func)(T &item))
{
	if (!arr || !func)
		return;
	for (unsigned int i = 0; i < arr_len; i++)
		func(arr[i]);
}

#endif