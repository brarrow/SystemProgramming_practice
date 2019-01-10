#include <iostream>
#include <vector>
#include <math.h>
#include "../../Ex5IterMerge/src/Ex5IterMerge/MergeSort.hh"
#include "ThreadSort.hh"

using namespace std::chrono;

int main()
{
    std::cout.fill(' ');

    std::vector<double> vecNorm;
    std::vector<double> vecThread;

    steady_clock::time_point start;
    steady_clock::time_point end;

    std::cout << "Elements";
    std::cout.width(15);
    std::cout << "NonThreaded";
    std::cout.width(15);
    std::cout << "Threaded" << std::endl;

    for (int i = 3; i < 7; i++)
    {
        vecNorm.clear();
        vecThread.clear();
        for (double j = pow(10, i); j > 0; j--)
        {
            vecNorm.push_back(j);
            vecThread.push_back(j);
        }
        std::cout << "10^" << i;

        start = steady_clock::now();
        mergeSort(vecNorm.begin(), vecNorm.end());
        end = steady_clock::now();
        std::cout.width(15);
        std::cout << duration_cast<milliseconds>(end - start).count() << " ms";

        start = steady_clock::now();
        mergeSortThread(vecThread.begin(), vecThread.end());
        end = steady_clock::now();
        std::cout.width(15);
        std::cout << duration_cast<milliseconds>(end - start).count() << " ms";
        std::cout << std::endl;
    }
    return 0;
}
