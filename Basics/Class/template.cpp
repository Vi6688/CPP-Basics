#include <iostream>
#include <chrono>
using namespace std;
template <typename T>
class Calculator
{
public:
    inline T add(const T &a,const  T &b) const 
    {
        return a + b;
    }
    inline T subtract(const T &a,const  T &b) const 
    {
        return a - b;
    }
    inline T multiply(const T &a,const  T &b) const 
    {
        return a * b;
    }
    inline T divide(const T &a,const  T &b) const 
    {
        if (b == 0)
        {
            cout << "divide by zero error";
            return 0;
        }
        return a / b;
    }
};

int main()
{
    auto duration = 0;
    int a;
    double b;
    Calculator<double> doubleCalc;
    Calculator<int> intCalc;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        a = intCalc.add(5, 4);
        a = intCalc.subtract(5, 4);
        a = intCalc.multiply(5, 4);
        a = intCalc.divide(5, 4);
        b = doubleCalc.add(5.4, 4.2);
        b = doubleCalc.subtract(5.6, 4.7);
        b = doubleCalc.multiply(5.8, 4.9);
        b = doubleCalc.divide(5.4, 4.9);
        auto end = std::chrono::high_resolution_clock::now();
        duration = duration + std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
    cout << "time taken: " <<static_cast<double>(duration) / 1000 << endl;
}