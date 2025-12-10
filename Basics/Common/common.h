#pragma once
#include "Vector.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
namespace v {
using namespace std;

inline void readCsv(Vector<Vector<string>> &data) {
  ifstream inputFile("Basics/Railway/user.csv");
  if (!inputFile.is_open()) {
    cerr << "Failed to open input.csv" << endl;
    return;
  }

  string line;

  while (getline(inputFile, line)) {
    Vector<string> row;
    stringstream ss(line);
    string value;

    while (getline(ss, value, ',')) {
      row.push_back(value);
    }
    data.push_back(row);
  }
  inputFile.close();
}

template <typename T> void printArray(const T a, const int &length) {
  for (int i = 0; i < length; i++) {
    // cout << "value at position " << i << " is " << *(a + i) << endl;
    cout << "value at position " << i << " is " << a[i] << endl;
  }
}
template <typename T>

void printArray(const T a, const int rows, const int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
template <typename T> void setArray(const T a, const int &length) {
  for (int i = 0; i < length; i++) {
    a[i] = (i + 1);
  }
}

template <typename T> inline void println(const T &m) { std::cout << m; }

template <typename T> inline void print(const T &m) { std::cout << m << endl; }
inline void print() { std::cout << endl; }

template <typename T> void printVector(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &element : vec) {
    std::cout << element << " ";
  }
  std::cout << "]" << std::endl;
}
inline void clrscr() { system("clear"); }
template <typename T> void printError(const T &error) {
  print("********************");
  print(error);
  print("********************");
}
template <typename T>

void printRow(const vector<T> &vec) {
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (it == vec.end() - 1) {
      cout << *it << endl;
      continue;
    }
    cout << *it << setw(15);
  }
}

} // namespace v