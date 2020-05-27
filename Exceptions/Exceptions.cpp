
#include <iostream>

void mightGoWrong();  
void useMightGoWrong()
{
    mightGoWrong();
}

class CanGoWrong
{
public:
    
};


int main()
{
    try {
        useMightGoWrong();
    }
    catch (int e)
    {
        std::cout << "Error code: " << e << std::endl;
    }
    catch (const char* e)
    {
        std::cout << "Error code: " << e << std::endl;
    }
    catch (std::string& e)
    {
        std::cout << "Error code: " << e << std::endl;
    }

    std::cout << "Still running" << std::endl; 

    try
    {
        CanGoWrong wrong;
    }
    catch(std::bad_alloc& e)
    {
        std::cout << e.what();
    }
}

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = true;

    if (error1)
    {
        throw "Sth went wrong";
    }

    if (error2)
    {
        throw std::string("Some string went wrong");
    }

    throw 8;
}