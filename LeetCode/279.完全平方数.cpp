/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (57.66%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    85.6K
 * Total Submissions: 148.2K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> sqrt_num;
        int base = 1;
        // int diff = 3;
        while(base*base <= n)
        {
            sqrt_num.push_back(base*base);
            base += 1;
        }

        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = 65535;
            for(int sq : sqrt_num)
            {
                if(sq > i) break;
                dp[i] = min(dp[i], dp[i-sq]+1);
            }
        }
            
        return dp[n];
    }

};
// @lc code=end

