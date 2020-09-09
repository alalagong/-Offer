/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        std::unordered_map<char, char> aeiou;
        aeiou.emplace('a', 1);   aeiou.emplace('e', 1);
        aeiou.emplace('i', 1);   aeiou.emplace('o', 1);
        aeiou.emplace('u', 1);   aeiou.emplace('A', 1);
        aeiou.emplace('E', 1);   aeiou.emplace('I', 1);
        aeiou.emplace('O', 1);   aeiou.emplace('U', 1);

        int i = 0;
        int j = s.length() - 1;

        while(i < j)
        {
            if(aeiou.find(s[i]) == aeiou.end())
            {
                ++i;
                continue;
            }
            if(aeiou.find(s[j]) == aeiou.end())
            {
                --j;
                continue;
            }

            swap(s[i++], s[j--]);
        }
        return s;
    }
};
// @lc code=end

