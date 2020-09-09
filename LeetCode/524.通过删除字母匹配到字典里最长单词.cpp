/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (46.22%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissions: 39.2K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * 输出: 
 * "apple"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * 输出: 
 * "a"
 * 
 * 
 * 说明:
 * 
 * 
 * 所有输入的字符串只包含小写字母。
 * 字典的大小不会超过 1000。
 * 所有输入的字符串长度不会超过 1000。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    static bool comp(const string &d1, const string &d2)
    {
        if(d1.length() > d2.length())
            return true;
        if(d1.length() < d2.length())
            return false;
        return d1 < d2;
    }

    // 从 s2 里面找 s1
    bool isSubstr(string &s1, string &s2)
    {
        int p1 = 0;
        int p2 = 0;
        int size1 = s1.size();
        int size2 = s2.size();

        while(p1 < size1 && p2 < size2)
        {
            if(s1[p1] == s2[p2])
            {
                if(p1 == size1-1)
                    return true;
                ++p1;
            }
            ++p2;          
        }
        return false;
    }

    string findLongestWord(string s, vector<string> &d)
    {
        vector<string> d1(d);

        sort(d1.begin(), d1.end(), comp);
        
        for(int i = 0; i < d.size(); i++)
        {
            if(isSubstr(d1[i], s))
                return d1[i];
        }
        return "";
    }
};
// @lc code=end
