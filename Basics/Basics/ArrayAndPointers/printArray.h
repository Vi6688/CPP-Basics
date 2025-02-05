#include <iostream>

using namespace std;

template <typename T>
void printArray(const T a, const int &length)
{
    for (int i = 0; i < length ; i++)
    {
        // cout << "value at position " << i << " is " << *(a + i) << endl;
        cout << "value at position " << i << " is " << a[i] << endl;
    }
}
template <typename T>

void printArray(const T a, const int rows, const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << a[i][j]<<" ";
        }
        cout<<endl;
    }
}