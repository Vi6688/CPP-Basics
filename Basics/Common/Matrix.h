#pragma once
#include "Vector.h"
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace v {

template <typename T> using MatrixXd = Vector<Vector<T>>;

/* ========================= ROW PROXY ========================= */

template <typename T> class Row {
private:
  MatrixXd<T> *matrix;
  size_t rowIndex;

public:
  Row(MatrixXd<T> *m, size_t r) : matrix(m), rowIndex(r) {}

  auto operator[](size_t col) {
    return (*matrix)[rowIndex][col]; // returns VectorElement<T>
  }

  auto operator[](size_t col) const { return (*matrix)[rowIndex][col]; }

  size_t size() const { return (*matrix)[rowIndex].size(); }
};

/* ========================= MATRIX ========================= */
template <typename T> class Matrix {
private:
  MatrixXd<T> data;

public:
  /* -------- Constructors -------- */
  Matrix() = default;

  Matrix(size_t rows, size_t cols) {
    data.resize(rows);
    for (auto &r : data)
      r.resize(cols);
  }

  Matrix(const MatrixXd<T> &d) : data(d) {}

  Matrix(std::initializer_list<std::initializer_list<T>> list) {
    data.resize(list.size());
    size_t i = 0;
    for (const auto &row : list) {
      data[i].resize(row.size());
      size_t j = 0;
      for (const auto &v : row)
        data[i][j++] = v;
      ++i;
    }
  }

  /* -------- Assignment -------- */
  Matrix &operator=(const MatrixXd<T> &rhs) {
    data = rhs;
    return *this;
  }

  /* -------- Indexing -------- */
  Row<T> operator[](size_t row) {
    if (row >= data.size())
      throw std::out_of_range("Row index out of range");
    return Row<T>(&data, row);
  }

  auto operator[](size_t row) const {
    if (row >= data.size())
      throw std::out_of_range("Row index out of range");
    return data[row]; // VectorElement<Vector<T>>
  }

  /* -------- Size -------- */
  size_t noOfRows() const { return data.size(); }
  size_t noOfColumns() const { return data.isEmpty() ? 0 : data[0].size(); }

  /* -------- Transpose -------- */
  Matrix transpose() const {
    Matrix result(noOfColumns(), noOfRows());
    for (size_t i = 0; i < noOfRows(); ++i)
      for (size_t j = 0; j < noOfColumns(); ++j)
        result[j][i] = data[i][j];
    return result;
  }

  /* -------- Multiplication -------- */
  Matrix operator*(const Matrix &other) const {
    if (noOfColumns() != other.noOfRows())
      throw std::invalid_argument("Matrix dimensions mismatch");

    Matrix result(noOfRows(), other.noOfColumns());

    for (size_t i = 0; i < noOfRows(); ++i)
      for (size_t j = 0; j < other.noOfColumns(); ++j) {
        T sum{};
        for (size_t k = 0; k < noOfColumns(); ++k)
          sum += data[i][k] * other[k][j];
        result[i][j] = sum;
      }
    return result;
  }

  /* -------- Inverse (Gauss-Jordan, DOUBLE ONLY) -------- */
  // Matrix<double> inverse() const {
  //   static_assert(std::is_same_v<T, double>,
  //                 "Inverse only supported for double");

  //   size_t n = noOfRows();
  //   if (n != noOfColumns())
  //     throw std::runtime_error("Matrix must be square");

  //   Matrix<double> aug(n, 2 * n);

  //   for (size_t i = 0; i < n; ++i) {
  //     for (size_t j = 0; j < n; ++j)
  //       aug[i][j] = data[i][j];
  //     aug[i][n + i] = 1.0;
  //   }

  //   for (size_t i = 0; i < n; ++i) {
  //     double pivot = aug[i][i];
  //     if (std::fabs(pivot) < 1e-12)
  //       throw std::runtime_error("Singular matrix");

  //     // for (size_t j = 0; j < 2 * n; ++j)
  //     //   aug[i][j] /= pivot;

  //     // for (size_t k = 0; k < n; ++k) {
  //     //   if (k == i)
  //     //     continue;
  //     //   double f = aug[k][i];
  //     //   for (size_t j = 0; j < 2 * n; ++j)
  //     //     aug[k][j] -= f * aug[i][j];
  //     }
  //   }

  //   Matrix<double> inv(n, n);
  //   for (size_t i = 0; i < n; ++i)
  //     for (size_t j = 0; j < n; ++j)
  //       inv[i][j] = aug[i][n + j];

  //   return inv;
  // }

  /* -------- Printing -------- */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (size_t i = 0; i < m.noOfRows(); ++i) {
      os << "{ ";
      for (size_t j = 0; j < m.noOfColumns(); ++j)
        os << m.data[i][j] << " ";
      os << "}\n";
    }
    return os;
  }
};

} // namespace v
