/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c < 0)
            return false;
        long min = 0;
        long max = sqrt(c);

        while (min <= max)
        {
            long long norm = min * min + max * max;

            if (norm > c)
                --max;

            if (norm < c)
                ++min;

            if (norm == c)
                return true;
        }

        return false;
    }
};
// @lc code=end
