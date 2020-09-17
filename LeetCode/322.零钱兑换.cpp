/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (41.17%)
 * Likes:    821
 * Dislikes: 0
 * Total Accepted:    135K
 * Total Submissions: 326.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return 0;
        if(amount == 0)
            return 0;

        vector<int> dp(amount+1, 0);
        // dp[0] = 1;
        for(auto it : coins)
        {
            for(int i = it; i <= amount; ++i)
            {
                if(i == it)
                    dp[i] = 1;
                else if(dp[i-it] != 0)
                    dp[i] = dp[i] == 0 ? dp[i-it]+1 : min(dp[i], dp[i - it]+1);
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};
// @lc code=end

