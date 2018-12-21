#include <iostream>
#include <vector>
#include "MergeSort.hh"
#include "MyIterator.hh"

int main()
{
    MyIterator<int> itr(std::cout, 2);
    std::vector<int> vector;

    for (int i = 10; i >= 0; i--)
    {
        std::cout << i << " ";
        vector.push_back(i);
    }
    std::cout << std::endl;
    auto pointer = vector.begin();

    while (pointer != vector.end())
    {
        *itr++ = *pointer++;
    }
    std::cout << *vector.begin() << std::endl;
    mergeSort(vector.begin(), vector.end());

    for (int x : vector)
        std::cout << x << " ";
    return 0;
}
