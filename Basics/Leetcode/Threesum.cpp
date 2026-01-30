#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  static bool checkDuplicates(vector<vector<int>> &sums,
                              const vector<int> &match) {
    int matchCount = 0;
    for (auto sum : sums) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            if (i != j && j != k && i != k) {

              if (sum == vector<int>{match[i], match[j], match[k]}) {
                return true;
              }
            }
          }
        }
      }
    }
    return false;
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    size_t vecSize = nums.size();
    if (vecSize == 3) {
      if ((nums[0] + nums[1] + nums[2]) == 0) {
        return {nums};
      } else {
        return {};
      }
    }
    vector<vector<int>> sum;
    for (int i = 0; i < vecSize - 2; i++) {
      for (int j = 1; j < vecSize - 1; j++) {
        for (int k = 2; k < vecSize; k++) {
          if (i == j || j == k || i == k) {
            continue;
          }
          if ((nums[i] + nums[j] + nums[k]) == 0) {
            cout << "Found match: " << nums[i] << ", " << nums[j] << ", "
                 << nums[k] << endl;
            vector<int> match = {nums[i], nums[j], nums[k]};
            if (!sum.size() || !checkDuplicates(sum, match)) {
              sum.push_back(match);
            }
          }
        }
      }
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-100, -70, -60, 110, 120, 130, 160};
  vector<vector<int>> value = sol.threeSum(nums);

  for (vector<int> a : value) {
    for (auto b : a)
      cout << b << ", ";
    cout << endl;
  }
}