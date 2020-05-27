

#include <iostream>
#include <utility>

void process(int&);
void process(int&&);

template <typename T>
void pass(T&&);



int main()
{
    int x = 7;
    std::cout << "Using LHS input" << std::endl;
    pass(x);
    std::cout << "Using RHS input" << std::endl;
    pass(7);
}

void process(int& passed)
{
    std::cout << "      LHS reference passed" << std::endl;
}
void process(int&& passed)
{
    std::cout << "      RHS reference passed" << std::endl;
}


template <typename T>
void pass(T&& t)
{
    std::cout << "  Passing normal value:" << std::endl;
    process(t);
    std::cout << "  Passing with move operator :" << std::endl;
    process(std::move(t));
    std::cout << "  Passing with forward operator :" << std::endl;
    process(std::forward<T>(t));
    std::cout << "  Passing with static cast :" << std::endl;
    process(static_cast<T&&>(t));
}