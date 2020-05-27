#include "Beta.h"


int main()
{
    Beta<double> guy(3.5, 3);
    guy.Show();
    std::cout << guy.blab(10, 2.3) << std::endl;
    std::cout << guy.blab(10.0, 2.3) << std::endl;
}
