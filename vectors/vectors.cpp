#include <iostream>
#include <vector>

template <typename T>
void vector_size(std::vector<T>& t)
{
    std::cout << "Size: " << t.size() << std::endl;
}



int main()
{
    std::vector<double> Numbers;
    Numbers.reserve(5);
    int capacity = Numbers.capacity();
    vector_size(Numbers);

    for (int i = 0; i < 1000; i++)
    {
        if (Numbers.capacity() != capacity)
        {
            capacity = Numbers.capacity();
            std::cout << capacity << std::endl;
        }
        Numbers.push_back(i);
    }
    vector_size(Numbers);
    Numbers.resize(100);
    vector_size(Numbers);

    // 2D vector

    std::vector< std::vector<int> > grid( 3, std::vector<int>( 4,7 ) );
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            std::cout << grid[i][j];
}

