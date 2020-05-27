
#include <iostream>
#include <vector>
#include <mutex>

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start, unsigned int end)
{
    for (auto x = start; x < end; x++)
        for (auto y = 2; y < x; y++)
        {
            if ((x % y) == 0)
                break;
            else if ((y + 1) == x)
            {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
}

void FindPrimesWithThreads(unsigned int start, 
                        unsigned int end, 
                    unsigned int numOfTHreads)
{
    std::vector<std::thread> threadVector;
    auto threadSpread = end / numOfTHreads;
    auto newEnd = start + threadSpread - 1;
    for (unsigned int i; i < numOfTHreads; i++)
    {
        threadVector.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    for (auto& t : threadVector)
        t.join();
}

int main()
{
    FindPrimesWithThreads(1, 1000, 10);
}
