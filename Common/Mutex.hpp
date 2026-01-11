#pragma once
#include <mutex>

namespace v {

class Mutex {
private:
  std::mutex _mutex;

public:
  void lock() { _mutex.lock(); }
  void unlock() { _mutex.unlock(); }
};

class MutexLock {
private:
  Mutex &_mutex;
public:
  MutexLock(Mutex &mutex) : _mutex(mutex) { _mutex.lock(); }
  ~MutexLock() { _mutex.unlock(); }
};

} // namespace v