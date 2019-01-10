#include <string>
#include <iostream>
#include "LineNumberBuffer.hh"
using namespace ::std;
int main()
{
    cout.rdbuf((new LineNumberBuffer(std::cout.rdbuf())));
    cout << cin.rdbuf();
    return 0;
}
