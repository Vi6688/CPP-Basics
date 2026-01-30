#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  map<string, int> romanNumerals = {{"I", 1},   {"V", 5},   {"X", 10},
                                    {"L", 50},  {"C", 100}, {"D", 500},
                                    {"M", 1000}};
  int romanToInt(string s) {
    int total = 0;
    int size = s.length();
    if (!size) {
      return 0;
    }
    for (int pos = 0; pos < size; pos++) {
      string romanLetter = s.substr(pos, 1);
      if (romanLetter == "I" || romanLetter == "X" || romanLetter == "C") {
        if (pos + 1 < size) {
          string nextRomanLetter = s.substr(pos + 1, 1);
          if ((romanLetter == "I" &&
               (nextRomanLetter == "V" || nextRomanLetter == "X")) ||
              (romanLetter == "X" &&
               (nextRomanLetter == "L" || nextRomanLetter == "C")) ||
              (romanLetter == "C" &&
               (nextRomanLetter == "D" || nextRomanLetter == "M"))) {
            total -= romanNumerals[romanLetter];
          } else {
            total += romanNumerals[romanLetter];
          }
        } else {
          total += romanNumerals[romanLetter];
        }
      } else {
        total += romanNumerals[romanLetter];
      }
    }
    return total;
  }
};
int main() {
  Solution sol;
  {
    cout << sol.romanToInt("MCMXCIV") << endl;
  }
  return 0;
}