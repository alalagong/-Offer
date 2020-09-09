/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    bool validSubPalindrome(string s)
    {
        int min = 0;
        int max = s.length() - 1;

        while (min <= max)
        {
            if (s[min] == s[max])
            {
                --max;
                ++min;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int min = 0;
        int max = s.length() - 1;

        while (min <= max)
        {
            if (s[min] == s[max])
            {
                --max;
                ++min;
            }
            else
            {
                // 两种选择
                return validSubPalindrome(s.substr(min, max - min)) || validSubPalindrome(s.substr(min+1, max - min));
            }
        }
        return true;
    }
};
// @lc code=end
