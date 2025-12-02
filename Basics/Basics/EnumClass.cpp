#include <iostream>
using namespace std;

enum class direction { UP, DOWN, RIGHT, LEFT };

int main() {

    cout << static_cast<int>(direction::UP) << endl;
}