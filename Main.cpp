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

  // Matrix<int> matrix1 = {{1, 2}, {1, 2}};
  // Matrix<int> matrix2 = {{1, 2}, {1, 2}};

  // cout << matrix1 << endl;
  // auto mulmatrix = matrix1 * matrix2;
  // cout << mulmatrix << endl;
  // cout << matrix1 << endl;
  // cout << matrix2 * mulmatrix << endl;
  // matrix1[0][0] = 100;
  using namespace std::chrono;
  long int average = 0;
  int numberOfTimes = 10;
  loopI(numberOfTimes) {
    Timer _;
    Vector<int> a = {1, 2};
    a.resize(100000);

    // a.resize(10, 0);
    // cout << a << endl;
  }
  std::cout << "Time taken: " << average / numberOfTimes << " nanoseconds\n";
  // cout << matrix1 << endl;
  return 0;
}