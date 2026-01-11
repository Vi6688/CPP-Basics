#pragma once
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace v {

template <typename T> class Vector;
template <typename T> class VectorElement {
  Vector<T> *_parent;
  size_t _index;

public:
  VectorElement(Vector<T> *parent, size_t index)
      : _parent(parent), _index(index) {}
  // Assignment: v[i] = value
  VectorElement &operator=(const T &value) {
    (*_parent).data()[_index] = value;
    return *this;
  }
  size_t size() { return (*_parent).data()->size(); }
  size_t size() const { return (*_parent).data()->size(); }

  void resize(const size_t &size) { (*_parent).data()[_index].resize(size); }
  void resize(const size_t &size, const T &fill) {
    (*_parent).data()[_index].resize(size, fill);
  }

  operator T() const { return (*_parent).data()[_index]; }

  auto operator[](const size_t &index) {
    return (*_parent).data()[_index][index];
  }
  auto operator[](size_t j) const { return (*_parent).data()[_index][j]; }

  auto data() { return (*_parent).data(); }
};
template <typename T>

class Vector {
private:
  T *_data = nullptr;
  size_t capacity = 0;
  size_t _size = 0;

public:
  Vector() = default;

  Vector(std::initializer_list<T> list) {
    _size = list.size();
    capacity = _size;
    _data = new T[_size];

    size_t i = 0;
    for (const T &val : list)
      _data[i++] = val;
  }

  Vector(size_t size, const T &fill) : _size(size), capacity(size) {
    _data = new T[size];
    for (size_t i = 0; i < size; i++)
      _data[i] = fill;
  }

  Vector(size_t size) : _size(size), capacity(size) { _data = new T[size]; }

  ~Vector() { delete[] _data; }

  T *data() { return _data; }

  // Copy constructor
  Vector(const Vector &other) : _size(other._size), capacity(other.capacity) {
    _data = new T[capacity];
    for (size_t i = 0; i < _size; i++)
      _data[i] = other._data[i];
  }

  Vector &operator=(const Vector &other) {
    if (this != &other) {
      delete[] _data;
      _size = other._size;
      capacity = other.capacity;
      _data = new T[capacity];
      for (size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
    }
    return *this;
  }

  const T &operator[](size_t index) const {
    if (index >= _size)
      throw std::out_of_range("Index out of range");
    return _data[index];
  }

  T &operator[](size_t index) {
    if (index >= _size)
      throw std::out_of_range("Index out of range");
    return _data[index];
  }


  void resize(size_t newSize) {
    T *newData = new T[newSize];
    size_t copySize = (newSize < _size) ? newSize : _size;
    if (copySize) {
      for (size_t i = 0; i < copySize; i++)
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
    capacity = newSize;
  }

  void resize(const size_t newSize, const T &fill) {
    T *newData = new T[newSize];
    for (int i = 0; i < newSize; i++) {
      newData[i] = fill;
    }
    delete[] _data;
    _data = newData;
    capacity = newSize;
  }

  void push_back(const T &value) {
    if (_size >= capacity)
      resize(capacity == 0 ? 1 : capacity * 2);

    _data[_size++] = value;
  }

  void pop_back() {
    if (_size == 0)
      throw std::out_of_range("Vector is empty");
    _size--;
  }

  size_t size() const { return _size; }
  size_t getCapacity() const { return capacity; }
  bool isEmpty() const { return _size == 0; }

  void print() const {
    std::cout << "{ ";
    for (size_t i = 0; i < _size; i++)
      std::cout << _data[i] << " ";
    std::cout << "}\n";
  }

  friend std::ostream &operator<<(std::ostream &os, const Vector &vec) {
    if (!vec._size) {
      os << "{ }";
      return os;
    }
    os << "{ ";
    for (size_t i = 0; i < vec._size; i++)
      os << vec._data[i] << " ";
    os << "}";
    return os;
  }

  T *insert(T *pos, const T &value) {

    size_t index = pos - begin();
    // Grow capacity if needed
    if (_size >= capacity) {
      size_t newCap = (capacity == 0) ? 1 : capacity * 2;
      resize(newCap);
    }

    if (_size == 1) {
      _data[0] = value;
      return begin();
    }
    // Shift elements to the right
    for (size_t i = _size - 1; i > index; --i) {
      _data[i] = _data[i - 1];
    }

    // Insert new element
    _data[index] = value;
    ++_size;

    return begin() + index;
  }

  auto begin() { return _data; }
  auto end() { return _data + _size; }
  auto begin() const { return _data; }
  auto end() const { return _data + _size; }
};

template <typename T> using AnyArray = Vector<T>;

} // namespace v
