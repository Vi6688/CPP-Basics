#include "SampleValues.h"
#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using namespace Eigen;

int main() {
  // Sample data
  vector<double> x_data = gain;
  vector<double> y_data = tx;

  for (int i = 0; i < y_data.size(); i++) {
    y_data[i] = pow(10, y_data[i] / 10);
  }

  int N = x_data.size();
  int degree = 5;
  // Set up matrix A (Vandermonde matrix) and vector Y
  MatrixXd A(N, degree + 1);
  VectorXd Y(N);

  for (int i = 0; i < N; ++i) {
    double x = x_data[i];
    for (int j = 0; j <= degree; ++j) {
      A(i, j) = pow(x, j);
    }
    Y(i) = y_data[i];
  }

  // Solve for coefficients using least squares
  VectorXd coeffs = A.colPivHouseholderQr().solve(Y);

  cout << "Fitted polynomial coefficients:\n";
  for (int i = degree; i >= 0; i--) {
    cout << coeffs(i) << ",";
  }
  cout << "\n";
  cout << "Fitted polynomial coefficients:\n";
  for (int i = degree; i >= 0; i--) {
    cout << x2(i) << ",";
  }
  cout << "\n";
  return 0;
}
