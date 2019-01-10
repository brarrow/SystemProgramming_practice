#include <algorithm>
#include <fstream>
#include <random>
#include "MyVector.hh"

using namespace::std;

int main()
{
  MyVector<ofstream> myVector;
  myVector.push_back(ofstream("a"));
  myVector.push_back(ofstream("b"));
  myVector.push_back(ofstream("c"));

  shuffle(myVector.begin(), myVector.end(), random_device());

  for (int i = 0; i < myVector.size(); i++)
  {
    myVector[i] << i;
  }

  return 0;
}