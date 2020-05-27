#pragma once

#include "myArray.h"

template <class T, int n>
myArray<T, n>::myArray(const T& t)
{
	for (int i = 0; i < n; i++)
		ar[i] = t;
}

template<class T, int n>
T& myArray<T, n>::operator[](int i)
{
	if (i < 0 || i > n)
	{
		std::cerr << "operator[] range error !!!!";
		exit(1);
	}
	else
		return ar[i];
}

template<class T, int n>
T myArray<T, n>::operator[](int i) const
{
	if (i < 0 || i > n)
	{
		std::cerr << "operator[] range error !!!!";
		exit(1);
	}
	else
		return ar[i];
}