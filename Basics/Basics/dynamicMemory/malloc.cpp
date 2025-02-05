#include <iostream>
#include "common.h"

using namespace std;
// always free the the memory allocated using malloc 
//malloc always return a void * hence need to type cast
// always try to use new and delete instead of malloc
void print()
{
    cout << "hello world" << endl;
}
int main()
{
    int *a = (int *)malloc(sizeof(int));
    *a = 10;
    cout << "value at a " << *a << ":" << sizeof(a) << ":" << a << endl;
    free(a);

    // creating an array of elements using malloc

    int *b =(int*)malloc(10*sizeof(int));
    setArray(b,10);
    printArray(b,10);
}