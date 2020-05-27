
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
auto length(T const& value)
{
    if constexpr (std::is_integral<T>::value)
        return value;
    else 
        return value.length();
}


int main()
{
    int value1 = 7;
    int* pValue1 = &value1;

    int* pValue2 = &++value1;     //lvalue
    // int* pValue3 = &value1++;  //rvalue, creates temp copy of value to be used
    // int* s = &(7 + value1);     ///rvalue

    // int& ref1 = value1++; nope
    const int&ref2 = value1++; //ok
    int n{ 64 };
    std::string s{ "Konik" };
    std::cout << "n: " << n << ", length: " << length(n) << std::endl;
    std::cout << "s: " << s << ", length: " << length(s) << std::endl;
}

 