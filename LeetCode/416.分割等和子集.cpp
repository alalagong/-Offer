/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (49.27%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    56.1K
 * Total Submissions: 113.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        if(sum%2 != 0)
            return false;

        int size = nums.size();
        if(size == 0)
            return false;

        int cap = sum/2;
        vector<bool> dp(cap+1, false);
        dp[0] = true;

        for(auto it : nums)
        for(int i = cap; i >= it; --i)
        {
            dp[i] = dp[i] || dp[i - it];
        }
        return dp[cap];
    }
};
// @lc code=end

