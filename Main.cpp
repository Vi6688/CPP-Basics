#include "common.h"
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intValues = {1, 5, 10, 50, 100, 500, 1000};
  map<int, string> romanNumerals = {{1, "I"},   {5, "V"},   {10, "X"},
                                    {50, "L"},  {100, "C"}, {500, "D"},
                                    {1000, "M"}};
  string getValue(const int digit, const int &digitValue) {
    if (digitValue == 4) {
      return romanNumerals[(pow(10, digit))] +
             romanNumerals[(pow(10, digit) * 5)];
    }
    if (digitValue == 9) {
      return romanNumerals[(pow(10, digit))] +
             romanNumerals[(pow(10, digit) * 10)];
    }

    return "";
  }
  string intToRoman(int num) {
    string result = "";
    if (!num)
      return "";

    int remainder = num;
    int digits = 0;
    int digitValue = remainder % 10;
    result += getValue(digits, digitValue);
    while (remainder / 10) {
      remainder = remainder / 10;
      digits += 1;
      digitValue = remainder % 10;
      result = getValue(digits, digitValue) + result;
    }
    cout << endl;
    return result;
  }
};
int main() {
  Solution sol;
  {
    cout << sol.intToRoman(94) << endl;
  }
}