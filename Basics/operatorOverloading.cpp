#include "../Common/String.h"
#include "../Common/common.h"
#include "../Common/Vector.h"
using namespace v;
int main()
{
    //     A copy constructor is used to copy an object to a newly created object. That is, it’s used during
    // initialization, not during ordinary assignment. A copy constructor for a class normally has this
    // prototype:
    // String a = "";
    // String b = "10", c = "vijay";
    // a = a + b + c;
    // a.print();
    // a = a.substr(2, 2);
    // a.print();
    // std::cin >> a;
    // std::cout << a << std::endl;

    Vector<String> vec = {"vijay", "vijay"};
    // setArray(vec, 4);
    vec.push_back("vijay");
    vec.push_back("vijay");
    vec[0] = "v";
    vec[0] = vec[0] + vec[1];

    std::cout << vec << std::endl;

    AnyArray<int> ve(3);
    ve[0] = 12;
    ve[2] = 12;
    ve[1] = 1;
    ve.print();

    String s1 = "1", s2 = "123";
    print(s1<s2);
}