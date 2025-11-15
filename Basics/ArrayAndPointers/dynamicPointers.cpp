#include <iostream>
#include "printArray.h"

using namespace std;

int main()
{
    int rows, columns;
    cout << "Enter the number of rows and colums" << endl;
    cin >> rows >> columns;
    int **matrix= new int *[rows];
    for(int i =0 ;i<rows;i++)
    {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = i * columns + j;          }
    }
    printArray(matrix,rows,columns);
}