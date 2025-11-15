#include <iostream>
using namespace std;


int main()
{
    int matrix[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printArray(matrix,sizeof(matrix)/sizeof(matrix[0]),sizeof(matrix[0])/sizeof(int));
}