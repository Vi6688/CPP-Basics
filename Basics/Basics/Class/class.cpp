#include <iostream>
#include "class.h"

using namespace std;

void car::printCar()
{
    std::cout << "car name is " << name << std::endl;
    std::cout << "car model is " << model << std::endl;
}
car::car(const std::string &name,const  int &model)
{
    this->name = name;
    this->model = model;
}
paint::paint(std::string color)
{
    this->color = color;
}
void paint::carColor(car *&car1)
{
    std::cout << "the " << car1->name << " is " << color << " in color and the model is " << car1->model << std::endl;
}
int main()
{
    car carModel1 = car("vijay1", 2023);
    car carModel2 = car("vijay2", 2023);
    car carModel3 = car("vijay3", 2023);
    std::cout << carModel1.name<<endl;
    std::cout << carModel2.name<<endl;
    std::cout << carModel3.name<<endl;


    car *car1 = new car("ford",2023);
    paint *model = new paint("red");
    paint* model1 =new paint("orange");

    model->carColor(car1);
    model1->carColor(car1);
    delete car1;
    delete model;
}
