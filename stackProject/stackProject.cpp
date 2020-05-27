#include <iostream>
#include "myStack.h"
#include <string>
#include <vector>

int main()
{
myStack<std::string> stack_string;

std::string poped_string;

stack_string.push("aaa");
stack_string.push("bbb");
stack_string.pop(poped_string);

}


