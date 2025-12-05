#include "String.h"
#include "Vector.h"
#include <iostream>
using namespace std;
using namespace v;

int main() {
  Vector<int> vec = {1, 2, 3, 4, 5};
  vec.push_back(6);
  vec.print();

  Vector<String> strVec;

  for (int i = 0; i < 10; i++) {
    strVec.push_back("Hello");
  }
  strVec.push_back("World");
  strVec.print();
  cout << "Capacity: " << strVec.size() << endl;
  cout << "Capacity: " << strVec.getCapacity() << endl;


  return 0;
}