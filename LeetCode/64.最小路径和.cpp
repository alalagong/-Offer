/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.51%)
 * Likes:    658
 * Dislikes: 0
 * Total Accepted:    142.2K
 * Total Submissions: 210.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        if(cols == 0)
            return 0;
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[rows-1][cols-1] = grid[rows-1][cols-1];

        for(int i = rows-1; i >= 0; --i)
            for(int j = cols-1; j >= 0; --j)
            {
                if(i == rows-1 && j == cols-1)
                    continue;
                else if(i == rows-1)
                    dp[i][j] = dp[i][j+1] + grid[i][j];
                else if(j == cols-1)
                    dp[i][j] = dp[i+1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
            }
        return dp[0][0];
    }
};
// @lc code=end

