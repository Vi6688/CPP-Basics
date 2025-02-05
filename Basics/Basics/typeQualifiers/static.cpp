#include <iostream>

// declaring as a static variable means in cannot be accessed by other files
// it has internal linkage
// memory is allocated only once
// static function in a class can only access the static variable
// member variable in a class should be declared outside the class

using namespace std;

class staticAndExtern
{
public:
    static double warming;
    int var = 2;
    static void print()
    {
        cout << "global warming " << warming << endl;
    }
};

double staticAndExtern::warming = 0.3;
static const double warming = 0.4;

void local()
{
    double warming = 0.1;
    cout << "global warming " << warming << endl;
}

void external()
{
    cout << "global warming " << warming << endl;
}
int main()
{
    local();
    external();
    staticAndExtern var = staticAndExtern();
    var.print();
}