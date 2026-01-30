#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
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
    int num = digitValue;
    string result = "";
    while (num != 0) {
      if (num >= 5) {
        result += romanNumerals[(pow(10, digit) * 5)];
        num -= 5;
      } else {
        result += romanNumerals[(pow(10, digit))];
        num -= 1;
      }
    }
    return result;
  }
  string intToRoman(int num) {
    if (!num)
      return "";

    int remainder = num;
    int digits = 0;
    int digitValue = remainder % 10;
    string result = getValue(digits, digitValue);
    while (remainder / 10) {
      remainder = remainder / 10;
      digits += 1;
      digitValue = remainder % 10;
      result = getValue(digits, digitValue) + result;
    }
    return result;
  }
};
int main() {
  Solution sol;
  {
    cout << sol.intToRoman(1000) << endl;
  }
}