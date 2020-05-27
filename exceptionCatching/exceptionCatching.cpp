
#include <iostream>

void goesWrong()
{
    bool error1 = true;
    bool error2 = false;
    if (error1)
        throw std::bad_alloc();
    if (error2)
        throw std::exception();
}


// order of exception matter we should catch them from children to parents
int main()
{
    try{
        goesWrong();
    }
    catch (std::bad_alloc& e) {
        std::cout << "Catching bad_alloc: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Catching exception: " << e.what() << std::endl;
    }
    

}

