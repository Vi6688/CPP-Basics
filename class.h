#include <iostream>
class car
{
public:
    std::string name;
    int model;

public:
    car(const std::string &name,const int &model);
    void printCar();
};

class paint
{
public:
    std::string color;
    paint(std::string color);
    void carColor(car* &car1);
};