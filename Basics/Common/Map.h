#include <iostream>

namespace v {

template <typename F,typename S>

class Map
{
    private:
    F *data1;
    S *data2;
    public:
    Map():data1(nullptr),data2(nullptr);
}
}