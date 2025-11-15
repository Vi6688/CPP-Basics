#include <iostream>
#include <string>
using namespace std;

void hello()
{
    cout << "Hello World " << endl;
}
void sum()
{
    int a[] = {2, 10};

    cout << *(a) * *(a + 1) << endl;
}
int main()
{
    // Pointer Golden Rule: Always initialize a pointer to a definite and appropriate address before you
    //  apply the dereferencing operator (*) to it.

    // stores the address of a variable
    // for normal variable you need provide a address of opertator infront to asssign the address of a variable
    int a = 2;
    int *ptr = &a;
    cout << "value at a " << *ptr << endl;

    // indexing through pointers
    // for array you dont need to add address of opertator
    int b[] = {0, 1, 2, 3, 4};
    int *arr = b;

    for (int i = 0; i < sizeof(b) / sizeof(int); i++)
    {
        cout << "value at array;" << *(b + i) << endl;
    }

    // you can also do dynamic memory allocation
    int *e = new int;
    *e = 2002;
    cout << "value = " << *e << ": location = " << e << endl;

    // dynamic memory allocation of array
    int *p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << "value at p " << *(p + i) << endl;
    }
    delete[] p;
    // alternate method
    int *c = (int *)malloc(4);
    *c = 6;
    cout << "value at c :" << *c << endl;
    free(c);

    // you can also use function pointers
    void (*funcPtr)() = hello;
    funcPtr();

    // need to use * dereference for each declaration
    int *p1, *p2; // correct
    int *p3, p4;  // p3 pointer and p4 normal integer

    // pointer arithmetics
    sum();
    // string pointer

    string name = "vijay";
    cout << "value at the string pointer :" << name << endl;
    return 0;
}