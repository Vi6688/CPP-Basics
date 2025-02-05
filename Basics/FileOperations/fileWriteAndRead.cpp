#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Open a file for both input and output.
    // ios::in  : Open for reading.
    // ios::out : Open for writing.
    // ios::app : Append to the end of the file.
    fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);

    if (!file)
    {
        cerr << "Failed to open the file" << endl;
        return 1;
    }
    file << "\nHello world!\nThis is 12th standard computer science class";
    file.clear();
    file.seekg(0, std::ios::beg);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
}