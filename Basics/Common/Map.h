#include "Vector.h"
#include <list>
#include <utility>

namespace v {

template <typename F, typename S> class Pair {
public:
  F first;
  S second;

  Pair(const F &f, const S &s) : first(f), second(s) {}
  Pair() {}
  friend std::ostream &operator<<(std::ostream &os, const Pair<F, S> &p) {
    os << "{ " << p.first << " ," << p.second << " }";
    return os;
  }
};
template <typename F, typename S> using hash = Vector<Pair<F, S>>;

template <typename F, typename S> class Map {
private:
  hash<F, S> _table;

public:
  Map() {}
  Map(hash<F,S> table) : _table(table) {}
  Map(std::initializer_list<Pair<F, S>> table) : _table(table) {}
  S &operator[](const F &first) {
    for (int i = 0; i < _table.getSize(); i++) {
      if (_table[i].first == first)
        return _table[i].second;
    }
  }
  Pair<F, S> *begin() { return _table.begin(); }
  Pair<F, S> *end() { return _table.begin() + _table.getSize(); }
  Pair<F, S> *find(const F &first) {
    if (_table.size() <= 0)
      return nullptr;
    for (auto i = _table.begin(); i != _table.end(); i++) {
      if (i->first == first)
        return i;
      i++;
    }
    return nullptr;
  }
  size_t size() const { return _table.size(); }
  friend std::ostream &operator<<(std::ostream &os, const Map<F, S> &map) {
    os << "{ ";
    for (size_t i = 0; i < map.size(); i++) {
      os << map._table[i] << " ";
    }
    os << " }";
    return os;
  }
};
} // namespace v