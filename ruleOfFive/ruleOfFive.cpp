
#include <iostream>
#include <vector>
#include <memory>

class Test
{
private:
    static const int SIZE = 100;

    int* _pBuffer{ nullptr };
public:
    Test() { _pBuffer = new int[SIZE]; }
    Test(int i)
    {
        _pBuffer = new int[SIZE];
        for (int i = 0; i < SIZE; i++)
            _pBuffer[i] = 7 * i;

    }
    Test(const Test& test)
    {
        _pBuffer = new int[SIZE];
        memcpy(_pBuffer, test._pBuffer, SIZE * sizeof(int));
    }
    Test(Test&& test)
    {
        _pBuffer = new int[SIZE];
        _pBuffer = test._pBuffer;
        delete test._pBuffer;
    }
    Test& operator=(const Test& test)
    {
        std::cout << "Move constructor \n";
        _pBuffer = new int[SIZE];
        memcpy(_pBuffer, test._pBuffer, SIZE * sizeof(int));
        return *this;
    }
    Test& operator=(Test&& test)
    {
        std::cout << "move assignment operator \n";
        delete[] _pBuffer;
        _pBuffer = test._pBuffer;
        return *this;
    }

    ~Test()
    {
        std::cout << "Destructor\n";
        delete[] _pBuffer;
    }

    static int getSize() 
    { 
        int i = SIZE;
        return i; 
    }

    friend std::ostream &operator<<(std::ostream& out, const Test& test);
};

std::ostream &operator<<(std::ostream& out, const Test& test)
{
    int size = test.getSize();

    for (int i = 0; i < size ; i++)
    {
        out << test._pBuffer[i] << std::endl;
    }
    return out;
}

Test getTest()
{
    return Test();
}

int main()
{
    std::vector<Test> vec;
    vec.push_back(Test());
    Test test;
    test = getTest();
}