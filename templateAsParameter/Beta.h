#pragma once
#include <iostream>

template<typename T>
class Beta
{
private:
	template<typename V>
	class Hold
	{
	private:
		V value;
	public:
		Hold(V v = 0) : value(v) {}
		void Show() const { std::cout << value << std::endl; }
		V returnValue() const { return value; }
	};
	Hold<T> q;
	Hold<T> n;
public:
	Beta(T t, int i): q(t), n(i) {}
	template<typename U>
	U blab(U u, T t) { return (n.returnValue() + q.returnValue()) * u / t; }
	void Show() const { q.Show(); n.Show(); }
};