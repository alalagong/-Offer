/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (48.30%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 32.1K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        map<int, int> hash;

        for(auto it : nums)
            hash[it]++;
        
        int res = 0;
        for(auto it : hash)
        {
            if(hash.find(it.first+1) != hash.end())
            {
                int s1 = it.second + hash.find(it.first+1)->second;
                // int s2 = it.second + hash.find(it.first-1)->second;
                res = max(res, s1);
                // res = max(res, max(s1,s2));
            }
            
        }
        return res;
    }
};
// @lc code=end

