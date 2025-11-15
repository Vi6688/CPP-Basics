#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (auto const &num : nums2)
        {
            nums1.push_back(num);
        }
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        if (size % 2 == 0)
            return ((nums1[(size / 2) - 1] + nums1[size / 2]) / 2.0);
        else
            return nums1[size / 2];
    }
};

int main()
{
    vector<int> n1 = {1, 2};
    vector<int> n2 = {3, 4};
    Solution *sol = new Solution();
    double result = sol->findMedianSortedArrays(n1, n2);
    std::cout << result << std::endl;
}