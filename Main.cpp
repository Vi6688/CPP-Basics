#include "Timer.hpp"
#include "common.h"
#include <string>
#include <vector>


using namespace std;
using namespace v;

int main() {
  Timer a;
  loopI(100000) {
    vector<string> numbers = {"one", "two",   "three", "four", "five",
                              "six", "seven", "eight", "nine", "ten"};

    numbers[i % 10] = "number";
  }
  return 0;
}
