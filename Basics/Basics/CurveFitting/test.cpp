
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct states {
  bool state1 = false;
  bool state2 = false;
};
int main() {
  states local1;
  states remote;
  states &local = false ? remote : local1;
  map<string, bool *> structStates = {{"state1", &local.state1},
                                      {"state2", &local.state2}};

  for (auto &[state, val] : structStates) {
    *val = true;
  }
  cout << local1.state1 << endl;
  cout << local.state1 << endl;
  cout << remote.state1 << endl;
}