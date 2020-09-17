/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 *
 * https://leetcode-cn.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (55.86%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 20.2K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
 * 
 * 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
 * 
 * 给定一个对数集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 * 
 * 示例 :
 * 
 * 
 * 输入: [[1,2], [2,3], [3,4]]
 * 输出: 2
 * 解释: 最长的数对链是 [1,2] -> [3,4]
 * 
 * 
 * 注意：
 * 
 * 
 * 给出数对的个数在 [1, 1000] 范围内。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 0)
            return 0;
        sort(pairs.begin(), pairs.end(), [&](vector<int> &a1, vector<int> &a2){
            return a1[0] < a2[0];
        });
        vector<int> dp1(n+1, 1);
        // vector<int> dp2(n+1, 1);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(pairs[j-1][1] < pairs[i-1][0])
                    dp1[i] = max(dp1[i], dp1[j]+1);
                // if(pairs[i-1][1] < pairs[j-1][0])
                //     dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }

        int res = 0;
        for(int i = 0; i <= n; ++i)
            res = max(res, dp1[i]);
        return res;
    }
};
// @lc code=end

