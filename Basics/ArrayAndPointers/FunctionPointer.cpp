#include <iostream>
using namespace std;

int sum(const int &a,const int &b)
{
    return a+b;
}

int sum()
{
    return 2;
}

int main()
{
    int (*s)(const int &,const int &) = sum;
    int (*s1)() = sum;

    int a = 1, b = 2;
    cout << s(a,b) << endl;

    cout << s1() << endl;
}