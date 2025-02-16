#include <iostream>
using namespace std;

double lowerRange = 1;
double upperRange = 500;

double guess(const double &num, int &count, double currentNum = (upperRange / 2), double lower = lowerRange, double upper = upperRange)
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

double main()
{
    double number;
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