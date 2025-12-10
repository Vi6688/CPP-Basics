#pragma once
#include <cstring>
#include <iostream>

namespace v {
template <typename T> class Vector {
private:
  T *data;
  /* data */
  size_t capacity = 0;
  size_t _size = 0;

public:
  Vector() : data(nullptr) {}
  Vector(std::initializer_list<T> list) {
    data = new T[list.size()];
    _size = list.size();
    capacity = _size;
    auto it = list.begin();
    for (size_t i = 0; i < _size; i++) {
      data[i] = *it;
      it++;
    }
  }

  T *begin() { return data; }
  T *end() { return data + _size; }

  void resize(const size_t size) {
    T *newData = new T[_size];
    for (size_t i = 0; i < _size; ++i) {
      newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    _size = size;
    capacity = size;
  }

  void resize(const size_t size, const T &fill) {
    T *newData = new T[size];
    for (size_t i = 0; i < size; ++i) {
      newData[i] = fill;
    }
    _size = size;
    data = newData;
  }

  ~Vector() { delete[] data; }
  Vector(const Vector &other) : data(nullptr), _size(0), capacity(0) {
    data = new T[other.capacity];
    capacity = other.capacity;
    _size = other._size;
    for (size_t i = 0; i < _size; ++i) {
      data[i] = other.data[i];
    }
  }
  Vector(const size_t &size, const T &fill)
      : data(nullptr), _size(size), capacity(size) {
    data = new T[size];
    for (size_t i = 0; i < _size; ++i) {
      data[i] = fill;
    }
  }
  Vector(const size_t newCapacity) {
    data = new T[newCapacity];
    capacity = newCapacity;
    _size = newCapacity;
  }
  Vector &operator=(const Vector &other) {
    if (this != &other) {
      delete[] data;
      data = new T[other.capacity];
      capacity = other.capacity;
      _size = other._size;
      for (size_t i = 0; i < _size; ++i) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  void push_back(const T &value) {
    if (_size >= capacity) {
      resize(capacity == 0 ? 1 : capacity * 2); // Double the capacity
    }
    data[_size++] = value;
  }
  void pop_back() {
    if (_size > 0) {
      --_size;
    } else {
      throw std::out_of_range("Vector is empty");
    }
  }
  T &operator[](size_t index) {
    if (index >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }
  const T &operator[](size_t index) const {
    if (index >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }
  size_t size() const { return _size; }
  size_t getCapacity() const { return capacity; }
  bool isEmpty() const { return _size == 0; }
  // friend std::ostream &operator<<(std::ostream &os,const T &value)
  // {
  //     os << value;
  //     return os;
  // }
  friend std::ostream &operator<<(std::ostream &os, const Vector &vec) {
    if (vec.size()) {
      for (size_t i = 0; i < vec._size; ++i) {
        os << vec.data[i] << " ";
      }
    } else {
      os << "{}";
    }
    return os;
  }
  // friend std::istream &operator<<(std::ostream &os,const Vector &vec)
  // {
  //     os >> vec.data;
  //     return os;
  // }
  void print() const {
    if (_size) {
      for (size_t i = 0; i < _size; ++i) {
        std::cout << data[i] << " ";
      }
    } else {
      std::cout << "{ }" << std::endl;
    }
    std::cout << std::endl;
  }
};
template <typename T> using AnyArray = Vector<T>;
} // namespace v