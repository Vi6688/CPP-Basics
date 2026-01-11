#pragma once
#include <iostream>
#include <cstring>

namespace v {
class String {
private:
  char *data;

public:
  String() : data(nullptr) {}

  String(const char *str) {
    if (str) {
      data = new char[strlen(str) + 1];
      strcpy(data, str);
    } else {
      data = nullptr;
    }
  }
  String(const String &other) {
    if (other.data) {
      data = new char[strlen(other.data) + 1];
      strcpy(data, other.data);
    } else {
      data = nullptr;
    }
  }

  const char *get() const { return data; }

  String &operator=(const String &other) {
    if (this != &other) // Check for self-assignment
    {
      // First, clean up existing memory
      if (data != nullptr)
        delete[] data;
      // Then allocate new memory and copy the data
      if (other.data) {
        data = new char[strlen(other.data) + 1]; // Allocate memory for the copy
        strcpy(data, other.data);                // Copy the data
      } else {
        data = nullptr; // Handle the case where other.data is nullptr
      }
    }
    return *this;
  }

  String &operator=(const char &other) {
    if (data != nullptr)
      delete[] data;
    std::cout << "yes" << std::endl;

    data = new char[2];
    data[0] = other;
    data[1] = '\0';
    return *this;
  }

  String operator+(const char &other) {
    String newString;
    if (data != nullptr) {
      newString.data = new char[strlen(data) + 2];
      strcpy(newString.data, data);
      newString.data[strlen(data)] = other;
      newString.data[strlen(data) + 1] = '\0';
    } else {
      newString.data = new char[2];
      newString.data[0] = other;
      newString.data[1] = '\0';
    }
    return newString;
  }

  String operator+(const String &other) {
    String newString;
    if (other.data != nullptr && data != nullptr) {
      newString.data = new char[strlen(other.data) + strlen(data) + 1];
      strcpy(newString.data, data);
      strcat(newString.data, other.data);
    } else if (other.data != nullptr) {
      newString.data = new char[strlen(other.data) + 1];
      strcpy(newString.data, other.data);
    } else if (data != nullptr) {
      newString.data = new char[strlen(data) + 1];
      strcpy(newString.data, data);
    }

    return newString;
  }

  String substr(const int &pos, const int &len) {
    if (pos < 0 || pos >= strlen(data) || len <= 0)
      return String();
    int actualLen = std::min(len, int(strlen(data) - pos));
    String newString;
    newString.data = new char[actualLen + 1];

    for (int i = 0; i < actualLen; i++) {
      newString.data[i] = data[pos + i];
    }
    newString.data[actualLen] = '\0';
    return newString;
  }
  bool operator==(const String &other) {
    return (strcmp(data, other.data) == 0);
  }
  bool operator==(String &other) { return (strcmp(data, other.data) == 0); }
  bool operator!=(const String &other) {
    return !(strcmp(data, other.data) == 0);
  }
  bool operator>(const String &other) { return (strcmp(data, other.data) > 0); }
  bool operator<(const String &other) { return (strcmp(data, other.data) < 0); }
  bool operator>(const String &other) const {
    return (strcmp(data, other.data) > 0);
  }
  bool operator<(const String &other) const {
    return (strcmp(data, other.data) < 0);
  }
  bool empty() const { return data == nullptr; }
  friend std::ostream &operator<<(std::ostream &os, const String &other) {
    if (other.data) {
      os << other.data;
    } else {
      os << "Empty String";
    }
    return os;
  }
  friend std::istream &operator>>(std::istream &is, const String &other) {
    is >> other.data;
    return is;
  }
  void print() const {
    if (data != nullptr)
      std::cout << data << std::endl;
  }

  ~String() { delete[] data; }
};
} // namespace v