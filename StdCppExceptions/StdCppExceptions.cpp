
#include <iostream>

class CanGoWrong
{
public:
    CanGoWrong() { char* pMem = new char[999999999]; }
};
int main()
{
    try
    {
        CanGoWrong wrong;
    }
    catch (std::bad_alloc& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Main still running !";
}

