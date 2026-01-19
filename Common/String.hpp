#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
#include <string.h>

namespace v {

class String {
private:
  char *_data;

public:
  String() : _data(nullptr) {}

  String(const char *str) {
    if (!str)
      _data = nullptr;
    _data = new char[strlen(str) + 1];
    strcpy(_data, str);
  }

  String(const String &other) {
    if (other._data) {
      _data = new char[strlen(other._data) + 1];
      strcpy(_data, other._data);
    } else {
      _data = nullptr;
    }
  }

  const char *get() const { return _data; }

  String &operator=(const String &other) {
    if (this != &other) // Check for self-assignment
    {
      if (_data)
        delete[] _data;
      // Then allocate new memory and copy the data
      if (other._data) {
        _data =
            new char[strlen(other._data) + 1]; // Allocate memory for the copy
        strcpy(_data, other._data);            // Copy the data
      } else {
        _data = nullptr; // Handle the case where other.data is nullptr
      }
    }
    return *this;
  }

  String &operator=(const char &other) {
    if (_data) {
      delete[] _data;
    }
    _data = new char[2];
    _data[0] = other;
    _data[1] = '\0';
    return *this;
  }

  void reserve(const size_t &newSize) {
    if (_data)
      delete[] _data;
    _data = new char[newSize];
    _data[0] = '\0';
  }
  
  String &operator+(const char &other) {
    String newString;
    if (_data != nullptr) {
      newString._data = new char[strlen(_data) + 2];
      strcpy(newString._data, _data);
      newString._data[strlen(_data)] = other;
      newString._data[strlen(_data) + 1] = '\0';
    } else {
      newString._data = new char[2];
      newString._data[0] = other;
      newString._data[1] = '\0';
    }
    *this = newString;
    return *this;
  }

  String operator+(const String &other) {
    String newString;
    if (other._data != nullptr && _data != nullptr) {
      newString._data = new char[strlen(other._data) + strlen(_data) + 1];
      strcpy(newString._data, _data);
      strcat(newString._data, other._data);
    } else if (other._data != nullptr) {
      newString._data = new char[strlen(other._data) + 1];
      strcpy(newString._data, other._data);
    } else if (_data != nullptr) {
      newString._data = new char[strlen(_data) + 1];
      strcpy(newString._data, _data);
    }
    return newString;
  }

  String substr(const int &pos, const int &len) {
    if (pos < 0 || pos >= size() || len <= 0)
      return String();
    int actualLen = std::min(len, int(size() - pos));
    String newString;
    newString._data = new char[actualLen + 1];

    for (int i = 0; i < actualLen; i++) {
      newString._data[i] = _data[pos + i];
    }
    newString._data[actualLen] = '\0';
    return newString;
  }
  bool operator==(const String &other) {
    return (strcmp(_data, other._data) == 0);
  }
  bool operator==(String &other) { return (strcmp(_data, other._data) == 0); }
  bool operator!=(const String &other) {
    return !(strcmp(_data, other._data) == 0);
  }
  bool operator>(const String &other) {
    return (strcmp(_data, other._data) > 0);
  }
  bool operator<(const String &other) {
    return (strcmp(_data, other._data) < 0);
  }
  bool operator>(const String &other) const {
    return (strcmp(_data, other._data) > 0);
  }
  bool operator<(const String &other) const {
    return (strcmp(_data, other._data) < 0);
  }
  String &operator+=(const String &other) {
    *this = *this + other;
    return *this;
  }
  const char &operator[](const size_t &index) const {
    assert(index < size());
    return _data[index];
  }
  inline constexpr char &operator[](const size_t &index) {
    assert(index < size());
    return _data[index];
  }
  bool empty() const { return _data == nullptr; }
  friend std::ostream &operator<<(std::ostream &os, const String &other) {
    if (other._data) {
      os << other._data;
    } else {
      os << "Empty String";
    }
    return os;
  }
  friend std::istream &operator>>(std::istream &is, const String &other) {
    // is >> other.data;
    return is;
  }
  void print() const {
    if (_data != nullptr)
      std::cout << _data << std::endl;
    else
      std::cout << "Empty String" << std::endl;
  }

  inline constexpr size_t size() const {
    if (_data)
      return strlen(_data);
    return 0;
  }

  ~String() {
    if (_data)
      delete[] _data;
  }
};
} // namespace v