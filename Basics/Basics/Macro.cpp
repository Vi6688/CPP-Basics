#include <iostream>
using namespace std;

// square the given numbers
#define SQUARE(x) x *x

// stringification operator #
#define TO_STRING(x) (#x)

// token pasting operator 
#define CONCAT(x,y) x##y


int main()
{
    int n = 5;
    cout << SQUARE(n) << endl;

    cout << TO_STRING(HelloWorld!)<<endl;
    cout << CONCAT(Hello,World)<<endl;


//  Conditional Compilation
#ifdef DEBUG
    cout << "Debug Mode" << endl;
#else
    cout << "Release Mode" << endl;
#endif


}