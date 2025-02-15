#include "Inheritatnce.h"

using namespace v;

int main()
{
    Animal *ani = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    ani->eats();
    dog->eats();
    cat->eats();

    delete ani;
    delete dog;
    delete cat;
    return 0;
}
