#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}
int main()
{
    int n;
    cout << "Enter the factorial length :";
    cin >> n;
    cout << factorial(n) << endl;
}