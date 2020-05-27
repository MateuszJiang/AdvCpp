#pragma once

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class myString
{
	char* str;
	int strLength;
	static int strCount;
public:
	myString();
	myString(const char*);
	myString(const myString&);
	~myString();

	myString& operator=(const myString&);
	myString& operator=(const char*);

	char& operator[](int);
	const char& operator[](int) const;

	friend bool operator<(const myString&, const myString&);
	friend bool operator>(const myString&, const myString&);
	friend bool operator==(const myString&, const myString&);
	friend bool operator!=(const myString&, const myString&);

	friend std::ostream& operator<<(std::ostream&, const myString&);
	friend std::istream& operator>>(std::istream&, const myString&);

	int length() { return strLength; }
	static int numberOfmyStrings() { return strCount; }
};

int myString::strCount = 0; // static members must be initialized outside the class :<

#endif
