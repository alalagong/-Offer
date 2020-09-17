/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.19%)
 * Likes:    977
 * Dislikes: 0
 * Total Accepted:    144.7K
 * Total Submissions: 320.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n+1, 1);

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(nums[i-1] > nums[j-1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int max1 = 0;
        for(int i = 0; i <= n; ++i)
            max1 = max(max1, dp[i]);
        return max1;
    }
};
// @lc code=end

