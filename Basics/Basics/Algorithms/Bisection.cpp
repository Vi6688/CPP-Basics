#include <iostream>
using namespace std;

int lowerRange = 1;
int upperRange = 500;

int guess(const int &num, int &count, int currentNum = (upperRange / 2), int lower = lowerRange, int upper = upperRange)
{
    count++;
    if (num == currentNum)
    {
        return 0;
    }
    else if (num > currentNum)
    {
        lower = currentNum + 1;
        return guess(num, count, (lower + upper) / 2, lower, upper);
    }
    else if (num < currentNum)
    {
        upper = currentNum - 1;
        return guess(num, count, (lower + upper) / 2, lower, upper);
    }
    return 0;
}

int main()
{
    int number;
    cout << "Enter a number between " << lowerRange << " and " << upperRange << ": ";
    cin >> number;

    if (number < lowerRange || number > upperRange)
    {
        cout << "Invalid input! The number must be between " << lowerRange << " and " << upperRange << "." << endl;
        return 1;
    }

    int count = 0;
    guess(number, count);
    cout << "Number found in " << count << " attempts." << endl;

    return 0;
}