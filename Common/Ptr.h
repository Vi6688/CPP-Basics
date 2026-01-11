#pragma once
#include <memory>

namespace v {

template <typename T> class Ptr {
private:
  std::shared_ptr<T> _ptr;

public:
  Ptr(T *ptr) : _ptr(ptr) {}
  Ptr() = default;
  Ptr(const Ptr &) = default;
  Ptr(Ptr &&) = default;
  Ptr &operator=(const Ptr &) = default;
  Ptr &operator=(Ptr &&) = default;
  T *get() const { return _ptr.get(); }
  T *operator->() const { return _ptr.get(); }
  T &operator*() const { return *_ptr; }
};

} // namespace v
