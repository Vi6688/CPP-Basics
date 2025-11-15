#include <iostream>
// extern global variable can be declared only
// can be visible to external file if the extern keyword is used
// has external linkage so visibel across files
// can import c file {extern "C" void printMessage();}
// g++ -o test Basics/Basics/extern.cpp Basics/Basics/extern1.cpp && ./test
extern void printFunction();
extern int var123;
int main()
{
    printFunction();
    std::cout << "extern int variable " << var123 << std::endl;
}