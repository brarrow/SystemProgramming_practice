#include <iostream>
#include "MyArray.hh"
#include "Keeper.hh"


int main(){
	Keeper g(std::cout);
	std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
	std::cout << 228 << ' ';
	std::cout << 888;
}
