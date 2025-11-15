#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    string expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        string longest = "";
        for (int i = 0; i < s.size(); i++)
        {
            string palindrome1 = expandAroundCenter(s, i, i);
            string palindrome2 = expandAroundCenter(s, i, i + 1);
            if (palindrome1.size() > longest.size())
            {
                longest = palindrome1;
            }
            if (palindrome2.size() > longest.size())
            {
                longest = palindrome2;
            }
        }
        return longest;
    }
};

int main()
{

    // string s = "abcabcabc";
    // string s = "pwwkew";
    string s = "babab";
    Solution *sol = new Solution();
    string result = sol->longestPalindrome(s);
    cout << result << endl;
    return 0;
}
