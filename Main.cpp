#include "Ptr.h"
#include "String.hpp"
#include <atomic>
#include <iostream>
#include <thread>

using namespace std;
using namespace v;

class Name {
private:
  String name;

public:
  Name(String otherName) { name = otherName; }
  void set(String otherName) { name = otherName; }
  void printName() { cout << name << endl; }
};
typedef Ptr<Name> NamePtr;

int main() {
  
  NamePtr name = new Name("");

  name->set("Hii");
  name->printName();
}
