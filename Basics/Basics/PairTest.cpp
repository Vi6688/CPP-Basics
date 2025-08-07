
#include "../Common/Matrix.h"

using namespace v;

int main() {
  // Pair<String, int> _name = {"Vijay", 12};

  // std::cout << "Response name :" << _name.first << " age:" << _name.second
  //           << std::endl;

  // Map<String, int> _names = {{"vijay", 1}, {"vijay1", 2}};
  // std::cout << "Response " <<_names <<std::endl;

  Matrix<double> a = {{1,1,1},{1,1,1},{1,1,1}};

  a.printMatrix();
  Matrix<double> b  = a.transpose();
  b.printMatrix();
  // _names.begin();
} 