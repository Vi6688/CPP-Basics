#pragma once
#include "Vector.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <utility>

namespace v {

template <typename Key, typename Value> class Pair {
public:
  Key first;
  Value second;

  Pair(const Key &first, const Value &second) : first(first), second(second) {}
  Pair() {}
  friend std::ostream &operator<<(std::ostream &os, const Pair<Key, Value> &p) {
    os << "{ " << p.first << " ," << p.second << " }";
    return os;
  }
  Pair<Key, Value> &operator=(const Pair<Key, Value> &other) {
    first = other.first;
    second = other.second;
    return *this;
  }
  Value &operator[](const Key &key) {
    if (key == first)
      return second;
    throw std::out_of_range("Key not found");
  }
};

template <typename Key, typename Value> using hash = Vector<Pair<Key, Value>>;
template <typename Key, typename Value>
class Map {
private:
  Vector<Pair<Key, Value>> _table;

  void _sort() {
    std::sort(_table.begin(), _table.end(),
      [](const Pair<Key, Value>& a, const Pair<Key, Value>& b) {
        return a.first < b.first;
      });
  }

  Pair<Key, Value>* _binarySearch(const Key& key) {
    auto it = std::lower_bound(
      _table.begin(), _table.end(), key,
      [](const Pair<Key, Value>& a, const Key& b) {
        return a.first < b;
      });

    if (it == _table.end() || it->first != key)
      return nullptr;

    return it;
  }

public:
  Map() = default;

  Map(std::initializer_list<Pair<Key, Value>> list) : _table(list) {
    _sort();
  }

  size_t size() const { return _table.size(); }

  Pair<Key, Value>* begin() { return _table.begin(); }
  Pair<Key, Value>* end() { return _table.end(); }

  const Pair<Key, Value>* begin() const { return _table.begin(); }
  const Pair<Key, Value>* end() const { return _table.end(); }

  Value* find(const Key& key) {
    auto p = _binarySearch(key);
    return p ? &p->second : nullptr;
  }

  const Value* find(const Key& key) const {
    auto it = std::lower_bound(
      _table.begin(), _table.end(), key,
      [](const Pair<Key, Value>& a, const Key& b) {
        return a.first < b;
      });

    if (it == _table.end() || it->first != key)
      return nullptr;

    return &it->second;
  }

  /// operator[] — inserts if missing (std::map behavior)
  Value& operator[](const Key& key) {
    auto it = std::lower_bound(
      _table.begin(), _table.end(), key,
      [](const Pair<Key, Value>& a, const Key& b) {
        return a.first < b;
      });

    if (it == _table.end() || it->first != key) {
      auto emptyPair = Pair<Key, Value>(key, Value{});
      _table.push_back(emptyPair);

    }
    it = _table.end() - 1;

    // _sort();
    return it->second;
  }

  friend std::ostream& operator<<(std::ostream& os, const Map& map) {
    os << "{ ";
    for (const auto& p : map._table)
      os << p << " ";
    os << "}";
    return os;
  }
};

} // namespace v