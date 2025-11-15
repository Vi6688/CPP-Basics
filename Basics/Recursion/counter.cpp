#include <iostream>

using namespace std;

void printCounter(int count)
{
    if (count == 0)
        return;
    cout << "counting value :" << count << endl;
    printCounter(count-1);
}

int main()
{
    int counter = 10;
    printCounter(counter);
}