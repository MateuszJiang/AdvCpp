
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::string fileName = "stats.txt";
    std::ofstream outFile;
    outFile.open(fileName);
    if (outFile.is_open())
    {
        std::cout << "File opened, writing to it !" << std::endl;
        std::string stats = "USA: 330000000\nChina: 1400000000\n";
        outFile << stats;
        outFile.close();
    }
    else
        std::cerr << "Problem with file!";

    std::ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        return 1;
    }
    else
        std::cout << "File opened !" << std::endl;
 
    while (inFile)
    {
        std::string line;
        int population;

        std::getline(inFile, line, ':');
        inFile >> population;
        inFile >> std::ws; // takes care of 'enter'

        if (!inFile)
            break;
        std::cout << "Country: " << line << " population: " << population << std::endl;
    } 

    inFile.close();
}

