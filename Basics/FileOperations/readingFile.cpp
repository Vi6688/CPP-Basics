#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream readFile("example.txt");
    if (!readFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

  
    std::string line;
    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }

    readFile.close();
}