#pragma once
#include "Vector.h"
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <ostream>
namespace v {

template <typename T> using MatrixXd = Vector<Vector<T>>;
template <typename T> using Row = Vector<T>;

template <typename T> class Matrix {
private:
  MatrixXd<T> data;

public:
  Matrix();
  Matrix(const MatrixXd<T> &d) { data = d; }
  Matrix(const std::initializer_list<std::initializer_list<T>> &list) {
    data.resize(list.size());
    int i = 0;
    for (const auto &row : list) {
      data[i].resize(row.size());
      int j = 0;
      for (const T &val : row) {
        data[i][j] = val;
        ++j;
      }
      ++i;
    }
  }
  Matrix<T> &operator=(MatrixXd<T> &list) {

    data.resize(list.size());
    int i = 0;
    for (const auto &row : list) {
      data[i].resize(row.size());
      int j = 0;
      for (const auto &val : row) {
        data[i][j] = val;
        ++j;
      }
      std::cout << data[i] << std::endl;
      ++i;
    }
    return this;
  }
  Matrix(const int &rows, const int &columns) {
    data = Vector<Vector<T>>(rows, columns);
  }
  Matrix<T> transpose() {
    Vector<Vector<T>> result = Vector<Vector<T>>(data[0].size(), data.size());
    for (size_t i = 0; i < data.size(); ++i)
      for (size_t j = 0; j < data[0].size(); ++j)
        result[j][i] = data[i][j];
    return result;
  }

  Matrix<T> operator*(const Matrix<T> &other) {
    size_t rows = noOfRows();
    size_t cols = other.noOfColumns();
    size_t inner = noOfColumns();

    if (inner != other.noOfRows())
      throw std::invalid_argument(
          "Matrix Multiplication = Incompatible dimensions.");

    MatrixXd<T> result(rows, cols);

    for (size_t i = 0; i < rows; ++i)
      for (size_t j = 0; j < cols; ++j) {
        T sum = 0;
        for (size_t k = 0; k < inner; ++k) {
          sum += data[i][k] * other[k][j];
        }
        result[i][j] = sum;
      }

    return Matrix<T>(result);
  }

  MatrixXd<T> invertMatrix(const MatrixXd<T> &A) {
    int n = A.size();
    Matrix augmented(n, Vector<double>(2 * n));
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

    Matrix inverse(n, Vector<double>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        inverse[i][j] = augmented[i][n + j];
    return inverse;
  }

  Row<T> operator[](const int &row) const {
    if (row >= noOfRows()) {
      return {};
    } else {
      return data[row];
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
    if (!matrix.data.size()) {
      os << "{}";
    } else {
      for (size_t row = 0; row < matrix.data.size(); ++row) {
        os << "{ ";
        size_t columnSize = matrix.data[row].size();
        if (!columnSize)
          os << "Empty Column ";
        else {
          for (size_t colums = 0; colums < columnSize; colums++) {
            os << matrix.data[row][colums] << ", ";
          }
        }
        os << "}\n";
      }
    }
    return os;
  }
  size_t noOfRows() const { return data.size(); }
  size_t noOfColumns() const {
    if (!data.size() || !data[0].size())
      return 0;
    else
      return data[0].size();
  }
  void printMatrix() {
    for (const auto &row : data) {
      row.print();
    }
    std::cout << '\n';
  }
};
} // namespace v