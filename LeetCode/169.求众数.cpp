/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (57.99%)
 * Total Accepted:    28K
 * Total Submissions: 48.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
class Solution {

// * Use HashMap to count every number
// * Delete a pair of different number, the rest is solution. We use this.
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ret=0;
        for(int num:nums)
        {
            if(count == 0)
                ret = num;
            if(num == ret)
                ++count;
            else
                --count;
        }
        return ret;
    }
};

