#include <atomic>
#include <iostream>
#include <thread>
using namespace std;
class Ready {
public:
  static atomic<bool> ready;
};

int main() {

  Ready r1;
  Ready r2;

  if (!r1.ready) {
    std::cout << "not ready" << endl;
  }
  
  r2.ready = true;

  std::cout << r1.ready << endl;

  std::cout << "name" << endl;
}