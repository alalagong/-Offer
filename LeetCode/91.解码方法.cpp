/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.36%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    66.6K
 * Total Submissions: 272.4K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        // dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            int val = atoi(s.substr(i-1, 1).c_str());
            if(val != 0)
                dp[i] += dp[i-1];
            if(s[i-2] == '0')
                continue;
            int val2 = atoi(s.substr(i-2, 2).c_str());
            if(val2 <= 26)
                dp[i] += dp[i-2];
            // cout << i << " : " << val << endl;
        }
        return dp[n];
    }
};
// @lc code=end

