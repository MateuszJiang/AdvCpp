#include <iostream>
#include "myArray.h"

int main()
{
    myArray<int, 10> sums;
    myArray<double, 10> averages;
    myArray < myArray<int, 5>, 10 > twodimentionalArray;

    int i = 0;
    int j = 0;

    for (i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodimentionalArray[i][j] = (i + j) * (j + 1);
            sums[i] += twodimentionalArray[i][j];
        }
        averages[i] = (double)sums[i] / 5;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            std::cout.width(2);
            std::cout << twodimentionalArray[i][j];
        }
        std::cout << ": sum = " << sums[i] << "average: " << averages[i] << std::endl;
    }
}


