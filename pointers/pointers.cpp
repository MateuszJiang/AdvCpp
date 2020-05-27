

#include <iostream>

int main()
{
    char** array = new char* [10];
    for(int i = 0; i<10; i++)
        array[i] = new char[20];
}

