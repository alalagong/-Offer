/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (62.62%)
 * Total Accepted:    5.6K
 * Total Submissions: 9K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,3,2]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 * 
 */

//! 使用数字电路的思想，使用一个两位二进制数（a, b）来对记录nums里数字每一位的状态，每三个1就归零。
/*************************************
 *  a       b       c       a'      b'
 * 
 *  0       0       0       0       0
 *  0       1       0       0       1
 *  1       0       0       1       0
 *  
 *  0       0       1       0       1
 *  0       1       1       1       0
 *  1       0       1       0       0
************************************/
//! 每一位上的状态如上所示。因此我们可以定义int a, b来进行对nums中数字的所有位进行计数。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int c : nums)
        {
            int a_temp =  (a & (~b) & (~c)) | ((~a) & b & c); // 注意这里的临时变量，还不能改变a
            b = ((~a) & (b) & (~c)) | ((~a) & (~b) & (c));
            a = a_temp;
        }
        if(a == 0)
        {
            return b;
        }
        else
        {
            return false;
        }
        
        
    }
};

