
#include <iostream>
#include <memory>
using namespace std;

struct A {
  bool a = true;
};
struct B {
  bool b = false;
};

void useUnique() {
  auto a = make_unique<A>();
  cout << a->a << endl;
}
void useUnique1(shared_ptr<A> a) { cout << a->a << endl; }
void useUnique2(shared_ptr<A> a) { cout << a->a << endl; }

int main() {
  auto a = make_shared<A>();
  useUnique1(a);
  useUnique2(a);
  return 0;
}