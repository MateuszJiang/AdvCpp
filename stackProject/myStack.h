#pragma once

#ifndef MYSTACK_H_
#define MYSTACK_H_

template <typename T>
class myStack
{
private:
	enum { SIZE = 10 };
	T* items;
	int stackSize;
	int top;
public:
	explicit myStack(int size = SIZE);
	myStack(const myStack& st);
	~myStack() { delete[] items; }

	bool isEmpty() { return (top == 0); }
	bool isFull() { return (top == stackSize); }
	bool push(const T& item);
	bool pop(T& item);

	myStack& operator=(const myStack& st);
};

template <typename T>
myStack<T>::myStack(int size): stackSize(size), top(0) 
{
	items = new T[stackSize];
}

template <typename T>
myStack<T>::myStack(const myStack& st)
{
	stackSize = st.stackSize;
	top = st.top;
	items = new T[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template <typename T>
myStack<T>& myStack<T>::operator=(const myStack& st)
{
	if (this == &st)
		return *this;
	delete[] items;
	stackSize = st.stackSize;
	top = st.top;
	items = new T[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

template <typename T>
bool myStack<T>::push(const T& item)
{
	if (top < stackSize)
	{
		items[top++] = item;
		return true;
	}
	return false;
}


template <typename T>
bool myStack<T>::pop(T& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	return false;
}
#endif // !MYSTACK)H)
