#pragma once

#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <iostream>
#include <cstdlib>

template<typename T, int n>
class myArray
{
private:
	T ar[n];
public:
	myArray() {}
	explicit myArray(const T& t);
	virtual T& operator[](int i);
	virtual T operator[](int i) const;
};


#endif