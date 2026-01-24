#include <cstddef>
#include <cstdlib>

namespace v {

template <typename T> class Memory {
public:
  T *data = nullptr;
  Memory(const size_t &size) { allocate(size); }
  Memory() {}
  void allocate(const size_t &size) {
    if (!size) {
      data = nullptr;
    }
    data = new T[size];
  }

  void resize(const size_t size, const bool &copy = false) { allocate(size); }

  T &operator[](const size_t &size) { return data[size]; }

  ~Memory() {
    if (data != nullptr)
      delete[] data;
  }
};

} // namespace v