#include "mystring.h"

myString::myString()
{
	strLength = 1;
	str = new char[strLength + 1];
	str[0] = '\0';
	strCount++;
}

myString::myString(const char* s)
{
	strLength = std::strlen(s);
	str = new char[strLength + 1];
	std::strcpy(str,s);
	strCount++;
}

myString::myString(const myString& mS)
{
	strLength = mS.strLength;
	str = new char[strLength];
	std::strcpy(str, mS.str);
	strCount++;
}

myString::~myString()
{
	delete[] str;
	strCount--;
}