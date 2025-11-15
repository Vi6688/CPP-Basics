#include <iostream>

// new operator is used to allocate memory for object in the heap and it also invokes their constructor
// it is type safe (means it can ve used with any class int,float,Class)
//  improvement to malloc and free functions
// new throws an exception when fails

using namespace std;

class MyClass
{
public:
    int value;
    MyClass(int v) : value(v)
    {
        cout << "MyClass constructed with value: " << value << endl;
    }
    MyClass() : value(0)
    {
        cout << "MyClass constructed with value: " << value << endl;
    }
    ~MyClass()
    {
        cout << "MyClass destructed." << endl;
    }
};

int main()
{

    MyClass *ptr = new MyClass(8);
    cout << "Value: " << ptr->value << endl;
    delete ptr;

    MyClass *arr = new MyClass[3];
    arr[0].value = 10;
    arr[1].value = 20;
    arr[2].value = 30;
    delete[] arr;

    char buffer[sizeof(MyClass)];
    MyClass *ptr1 = new (buffer) MyClass(99);
    cout << "Value: " << ptr1->value << " : "<< sizeof(MyClass) << endl;
    // call the constructor manually since the delete should not be used here
    ptr1->~MyClass();

    return 0;
}
