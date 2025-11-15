#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    size_t vecSize = height.size();
    if (!vecSize)
      return 0;
    int maxArea = 0;
    int right = vecSize - 1;
    int left = 0;

    while (left < right) {
      maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
      height[left] < height[right] ? left++ : right--;
    }
    return maxArea;
  }
};

int main() {
  double average = 0;
  for (int i = 0; i < 10; i++) {
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution a = Solution();
    for (int i = 0; i < 10000000; i++)
      a.maxArea(height);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    average += elapsed.count();  }
  std::cout << "Elapsed time (seconds): " << average/10 << std::endl;
}