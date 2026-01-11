#include "String.hpp"
#include "Timer.hpp"
#include "Vector.hpp"
#include "common.h"
// #include <vector>

using namespace std;
using namespace v;

int main() {
  Timer a;

  Vector<double> vec = {1, 2, 3, 4, 5};
  loopI(1000000) { vec[i % 5] = i; }

  for (size_t i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;
  return 0;
}
