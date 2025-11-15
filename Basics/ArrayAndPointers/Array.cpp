#include <iostream>
#include <array>

using namespace std;



int main()
{
    // declaration of pointers
    int a[] = {1,2,3};
    char c[] = {'a','b','c'};
    string s[] = {"abc","abc","abc"};
    printArray(a,3);
    printArray(c,sizeof(c)/sizeof(char));
    printArray(s,3);
}