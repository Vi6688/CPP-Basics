#include "Map.h"
#include "Matrix.h"
#include "String.h"
#include "Timer.h"
#include "Vector.h"
#include "common.h"
#include <chrono>
#include <iostream>
#include <iterator>

using namespace std;
using namespace v;
using namespace chrono;

int main() {

  Matrix<int> matrix1 = {{1, 2}, {1, 2}};
  Matrix<int> matrix2 = {{1, 2}, {1, 2}};

  matrix2 = matrix1.transpose();

  cout << matrix1.transpose() << endl;
  // auto mulmatrix = matrix1 * matrix2;
  // cout << mulmatrix << endl;
  // cout << matrix1 << endl;
  // cout << matrix2 * mulmatrix << endl;

  // matrix1[0] = 100;

  // Vector<Vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  
  // mat[0][0] = 100;

  // auto row = mat[0];
  // cout << mat[0].size() << endl;
  // cout << mat << endl;
  return 0;
}