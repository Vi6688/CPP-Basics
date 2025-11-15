#include <iostream>
#include <cstdlib>

using namespace std;
void* operator new(size_t size) {
    cout << "Custom global operator new called, size: " << size << endl;
    void* p = malloc(size);
    if (!p) throw bad_alloc();
    return p;
}

void operator delete(void* p) noexcept {
    cout << "Custom global operator delete called." << endl;
    free(p);
}

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {
        cout << "MyClass constructed with value: " << value << endl;
    }
    ~MyClass() {
        cout << "MyClass destructed." << endl;
    }
};

int main() {
    MyClass* obj = new MyClass(123);
    delete obj;
    return 0;
}
