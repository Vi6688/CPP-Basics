#include "Vector.h"

using namespace std;

int main()
{

    vector<string> strVector = {"name", "class", "roll", "subject"};
    vector<int> vec = {4, 7, 2, 8, 1, 9, 1, 9};
   
    Sort(vec);
    Unique(vec);
    binarySearch(vec, 4);
    emplaceBack(vec, 4);
    print(vec);

    Sort(strVector);
    Unique(strVector);
    binarySearch(strVector,(string)"name1");
    print(strVector);
    

}

// push_back("maths");
// erase(begin() + 1);
// insert(begin() + 1, "class");
// push_front("v");