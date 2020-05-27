
#include <iostream>

template <typename T> void counts();
template <typename T> void report(T&);


template<typename TT>
class ClassWithFriends
{
    TT item;
    static int count;
public:
    ClassWithFriends(const TT& tt) : item(tt) { count++; }
    ~ClassWithFriends() { count--; }
    friend void counts<TT>();
    friend void report<>(ClassWithFriends<TT>&);
    template <typename A, typename B> friend void show(A&, B&);
};

template <typename TT>
int ClassWithFriends<TT>::count = 0;


template <typename A, typename B> void show(A& a, B& b)
{
    std::cout << a.item << " " << b.item << std::endl;
}

template <typename T>
void counts()
{
    std::cout << "Template sizeof: " << sizeof(ClassWithFriends<T>) << ", "
        << "Template counts: " << ClassWithFriends<T>::count << std::endl;
}

template <typename T>
void report(T& hf)
{
    std::cout <<  hf.item << std::endl;
}



int main()
{
    ClassWithFriends<int> one(10);
    ClassWithFriends<int> two(11);
    ClassWithFriends<double> three(10.5);
    report(one);
    report(two);
    report(three);
    counts<int>();
    counts<double>();
    show(three, one);
}

