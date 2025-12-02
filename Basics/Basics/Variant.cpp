#include <iostream>
#include <any>
using namespace std;

class Dog {
public:
    string bark() { return"Woof!\n"; }
};

class Cat {
public:
    string meow() { return "Meow!\n"; }
};

int main() {
    any animal;

    bool isDog = true;
    if (isDog) {
        animal = new Dog();
    } else {
        animal = new Cat();
    }

    // Access the stored object

    cout << any_cast<Dog*>(animal)->bark()<<endl;
}
