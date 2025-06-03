#include "SampleValues.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using Matrix = std::vector<std::vector<double>>;
using namespace std;
Matrix transpose(const Matrix &M) {
  Matrix result(M[0].size(), std::vector<double>(M.size()));
  for (size_t i = 0; i < M.size(); ++i)
    for (size_t j = 0; j < M[0].size(); ++j)
      result[j][i] = M[i][j];
  return result;
}

Matrix multiplyMatrices(const Matrix &A, const Matrix &B) {
  size_t rows = A.size(), cols = B[0].size(), inner = B.size();
  if (A[0].size() != inner)
    throw std::invalid_argument("Incompatible dimensions.");
  Matrix result(rows, std::vector<double>(cols, 0));
  for (size_t i = 0; i < rows; ++i)
    for (size_t j = 0; j < cols; ++j)
      for (size_t k = 0; k < inner; ++k)
        result[i][j] += A[i][k] * B[k][j];
  return result;
}

Matrix invertMatrix(const Matrix &A) {
  int n = A.size();
  Matrix augmented(n, std::vector<double>(2 * n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      augmented[i][j] = A[i][j];
  for (int i = 0; i < n; ++i)
    augmented[i][n + i] = 1.0;

  for (int i = 0; i < n; ++i) {
    double pivot = augmented[i][i];
    if (std::fabs(pivot) < 1e-12)
      throw std::runtime_error("Matrix is singular.");
    for (int j = 0; j < 2 * n; ++j)
      augmented[i][j] /= pivot;
    for (int k = 0; k < n; ++k) {
      if (k == i)
        continue;
      double factor = augmented[k][i];
      for (int j = 0; j < 2 * n; ++j)
        augmented[k][j] -= factor * augmented[i][j];
    }
  }

  Matrix inverse(n, std::vector<double>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      inverse[i][j] = augmented[i][n + j];
  return inverse;
}

void printMatrix(const Matrix &M, const std::string &label = "") {
  if (!label.empty())
    std::cout << label << ":\n";
  for (const auto &row : M) {
    for (double val : row)
      std::cout << std::setw(10) << val << " ";
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  // Step 1: Define A and Y
  // Matrix A = {
  //     {1, 1},
  //     {1, 2},
  //     {1, 3}
  // };

  // Matrix Y = {
  //     {6},
  //     {0},
  //     {0}
  // };
  vector<double> x_data = gain;
  vector<double> y_data = tx;

  for (int i = 0; i < y_data.size(); i++) {
    y_data[i] = pow(10, y_data[i] / 10);
  }

  int N = x_data.size();
  int degree = 5;
  // Set up matrix A (Vandermonde matrix) and vector
  Matrix A(N);
  Matrix Y(N);

  for (int i = 0; i < N; ++i) {
    double x = x_data[i];
    for (int j = 0; j <= degree; ++j) {
      A[i].push_back(pow(x, j));
    }
    Y[i] = {y_data[i]};
  }
  
  Matrix X = multiplyMatrices(invertMatrix( multiplyMatrices(transpose(A), A)), multiplyMatrices(transpose(A), Y));
  printMatrix(X, "Final solution X");

  return 0;
}
