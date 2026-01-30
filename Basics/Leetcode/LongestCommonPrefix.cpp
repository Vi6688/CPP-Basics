#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";

    string prefix = strs[0];
    std::size_t prefixSize = strs[0].size();
    string commonPrefix = "";
    if (!prefixSize) {
      return commonPrefix;
    }
    for (int i = 0; i < prefix.size(); i++) {
      bool found = true;
      for (int j = 1; j < strs.size(); j++) {
        if (i > strs[j].size() - 1) {
          return commonPrefix;
        }
        found = found && strs[j][i] == prefix[i];
      }
      if (found) {
        commonPrefix += prefix[i];
      } else {
        return commonPrefix;
      }
    }
    return commonPrefix;
  }
};

int main() {
  vector<string> str = {"flower", "flow", "flight"};
  Solution sol;

  cout << sol.longestCommonPrefix(str) << endl;
}