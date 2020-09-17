/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.44%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 102K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 数组非空，且长度不会超过 20 。
 * 初始的数组的和不会超过 1000 。
 * 保证返回的最终结果能被 32 位整数存下。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // DP
        int sum = 0;
        for(auto it : nums)
            sum += it;
        if(sum < S || (sum+S)%2 != 0)
            return 0;

        int cap = (sum+S)/2;
        vector<int> dp(cap+1, 0);
        dp[0] = 1;
        for(auto it : nums)
            for(int i = cap;i >= it; --i)
            {
                dp[i] = dp[i] + dp[i-it];
            }
        return dp[cap];

        // DFS 超时
        // return findTargetSumWays(nums, 0, S);
    }

    // int findTargetSumWays(vector<int>& nums, int start, unsigned int S) 
    // {
    //     if(start == nums.size())
    //     {
    //         return S == 0 ? 1 : 0;
    //     }
    //     return findTargetSumWays(nums, start+1, S + nums[start]) + findTargetSumWays(nums, start+1, S - nums[start]);
    // }
};
// @lc code=end

