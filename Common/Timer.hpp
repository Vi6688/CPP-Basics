#pragma once
#include <chrono>
#include <iostream>

namespace v {
class Timer {

public:
  Timer() { start = std::chrono::high_resolution_clock::now(); }
  Timer(long int *timeTaken) : _timeTaken(timeTaken) {
    start = std::chrono::high_resolution_clock::now();
  }
  long int runTime() {
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count();
  }

  ~Timer() {
    if (_timeTaken) {
      *_timeTaken += runTime();
    } else {
      std::cout << "Time taken: " << runTime() << " us\n";
    }
  }

private:
  long int *_timeTaken = nullptr;
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

} // namespace v