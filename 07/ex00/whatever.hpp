#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//swap
template<typename T>
void swap(T &one, T &two)
{
	T temp;
	temp = one;
	one = two;
	two = temp;
}


//min
template<typename T>
T &min(T &one, T &two)
{
	if (one < two)
		return one;
	else
		return two;
}

//max
template<typename T>
T &max(T &one, T &two)
{
	if (one > two)
		return one;
	else
		return two;
}

#endif