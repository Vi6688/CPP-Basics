#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> num_map; 
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i}; 
            }
            num_map[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol->twoSum(nums, target);
    for (auto const &num : result)
    {
        std::cout << num << std::endl;
    }
}