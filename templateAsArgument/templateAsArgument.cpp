

#include <iostream>
#include "myStack.h"

template < template <typename T> class classT>
class Crab
{
private:
    classT<int> intStack;
    classT<double> doubleStack;
public:
    Crab() {}
    bool push(int a, double x) { return intStack.push(a) && doubleStack.push(x); }
    bool pop(int& a, double& x) { return intStack.pop(a) && doubleStack.pop(x); }
};

int main()
{
    Crab<myStack> nebula;
    std::cout << (bool)nebula.push(1, 3.0);
    std::cout << nebula.push(3, 4.09);
    int oneInt = 1;
    double oneDouble = 4.09;
    std::cout << nebula.pop(oneInt, oneDouble);
}

