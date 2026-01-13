#include "Timer.hpp"
#include "common.h"

#include "Vector.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace v;

constexpr size_t N = 1E8;

/* ---------------- std::vector tests ---------------- */

void testStdVector() {
  cout << "\n=== std::vector tests ===\n";

  Timer timer;

  vector<int> v;
  for (size_t i = 0; i < N; ++i)
    v.push_back(i);

  cout << "push_back time: " << timer.elapsed() << " ns\n";

  timer.reset();
  long long sum = 0;
  for (size_t i = 0; i < v.size(); ++i)
    sum += v[i];

  cout << "index access time: " << timer.elapsed() << " ns\n";

  timer.reset();
  vector<int> copy = v;
  cout << "copy time: " << timer.elapsed() << " ns\n";

  timer.reset();
  vector<int> moved = std::move(copy);
  cout << "move time: " << timer.elapsed() << " ns\n";

  cout << "sum = " << sum << "\n";
}

/* ---------------- v::Vector tests ---------------- */

void testCustomVector() {
  cout << "\n=== v::Vector tests ===\n";

  Timer timer;

  Vector<int> v;
  for (size_t i = 0; i < N; ++i)
    v.push_back(i);

  cout << "push_back time: " << timer.elapsed() << " ns\n";

  timer.reset();
  long long sum = 0;
  for (size_t i = 0; i < v.size(); ++i)
    sum += v[i];
  cout << "index access time: " << timer.elapsed() << " ns\n";

  timer.reset();
  Vector<int> copy = v;
  cout << "copy time: " << timer.elapsed() << " ns\n";

  timer.reset();

  Vector<int> moved;
  moved.move(copy);
  cout << "move time: " << timer.elapsed() << " ns\n";

  cout << "sum = " << sum << "\n";
}

int main() {
  testStdVector();
  testCustomVector();
  return 0;
}
