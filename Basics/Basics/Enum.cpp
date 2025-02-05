#include <iostream>
using namespace std;

enum rainbow
{
    violet = 100,
    indigo = 102,
    blue = 103,
    green = 104,
    yellow = 105,
    orange = 106,
    red = 107
};
int main()
{
    rainbow band = violet;

    rainbow band1 ;

    cout << band + band << endl;
    cout << band1 << endl;

}