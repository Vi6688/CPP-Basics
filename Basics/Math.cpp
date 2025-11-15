#include <iostream>
#include <math.h>

using namespace std;

class Math
{
public:
    int a;
    float b;
    double c;
    Math(int a, float f, double d)
    {
        this->a = a;
        b = f;
        c = d;
    }
    ~Math();
};

int main()
{
    Math *m = new Math(-10, 12.2, 14.350001);
    cout << abs(m->a) << endl;
    cout << log(m->a) << endl;
    cout << ceil(m->c) << endl;
    cout << floor(m->c) << endl;
    cout << exp(m->c) << endl;
    cout << pow(m->c, 2) << endl;
    cout << sqrt(m->c) << endl;

    short int a;
    char b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(u_int64_t) << endl;
    cout << sizeof(u_int32_t) << endl;
    cout << sizeof(u_int16_t) << endl;
    cout << sizeof(u_int8_t) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    
}