#include "Map.h"
#include "Matrix.h"
#include "String.h"
#include "Vector.h"
#include <iostream>

using namespace std;
using namespace v;

int main() {

  Matrix<int> matrix1 = {{1, 2}, {1, 2}};
  Matrix<int> matrix2 = {{1, 2}, {1, 2}};
  cout << matrix1 << endl;

  // matrix.printMatrix();

  return 0;
}