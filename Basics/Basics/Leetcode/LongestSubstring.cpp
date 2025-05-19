#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int>
            charIndexMap;
        int start = 0, maxLength = 0;

        for (int end = 0; end < s.size(); end++)
        {
            char currentChar = s[end];
            if (charIndexMap.find(currentChar) != charIndexMap.end() &&
                charIndexMap[currentChar] >= start)
            {
                start = charIndexMap[currentChar] + 1;
            }
            charIndexMap[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        for (auto const &ch : charIndexMap)
        {
            cout << ch.first << ch.second << endl;
        }
        return maxLength;
    }
};

int main()
{

    // string s = "abcabcabc";
    string s = "pwwkew";

    Solution *sol = new Solution();
    int result = sol->lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
