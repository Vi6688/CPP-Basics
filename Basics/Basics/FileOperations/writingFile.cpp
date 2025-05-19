#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outputFile("example.txt");
    if (!outputFile)
    {
        cerr << "Failed to open the file " << endl;
        return 0;
    }
    outputFile << "hello World";
    outputFile.close();
    cout << "Successfully wrote the data " << endl;
}
// Include <fstream>: Provides file stream classes.
// Create ofstream outFile("example.txt"): Opens (and creates if not exist) a file named example.txt for writing.
// Check if the file opened correctly: If !outFile evaluates to true, an error occurred.
// Write using << operator: Similar to writing to the console.
// Close the file: It's a good practice to close the file once 