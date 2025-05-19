
#include "../Common/Map.h"
#include "../Common/String.h"
using namespace v;

int main() {
  Pair<String, int> _name = {"Vijay", 12};

  std::cout << "Response name :" << _name.first << " age:" << _name.second
            << std::endl;

  Map<String, int> _names = {{"vijay", 1}, {"vijay1", 2}};
  std::cout << "Response " <<_names <<std::endl;
  // _names.begin();
} 