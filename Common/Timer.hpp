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
  void reset() { start = std::chrono::high_resolution_clock::now(); }
  long int elapsed(bool print = false) {
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    auto timeTaken = duration.count();
    if (print)

      std::cout << "Time taken: " << timeTaken << " ns\n";
    return timeTaken;
  }

  ~Timer() {
    if (_timeTaken) {
      *_timeTaken += runTime();
    } else {
      std::cout << "Time taken: " << runTime() << " ns\n";
    }
  }

private:
  long int *_timeTaken = nullptr;
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

} // namespace v