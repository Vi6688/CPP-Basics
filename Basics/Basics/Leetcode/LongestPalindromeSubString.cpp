#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};

int main()
{

    // string s = "abcabcabc";
    // string s = "pwwkew";
    string s = "babad";
    Solution *sol = new Solution();
    string result = sol->longestPalindrome(s);
    cout << result << endl;
    return 0;
}
