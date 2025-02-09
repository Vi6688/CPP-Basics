#include <iostream>
#include "common.h"

using namespace std;
// always free the the memory allocated using malloc
// malloc always return a void * hence need to type cast
// always try to use new and delete instead of malloc
// a calloc is similar to malloc and it also assign values to the allocated memory

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

    int *b = (int *)malloc(10 * sizeof(int));
    // setArray(b, 10);
    // printArray(b, 10);
    free(b);

    int size = 5;
    int *c = (int *)calloc(size, sizeof(int));
    setArray(c, size);
    printArray(c, size);
    free(c);
}