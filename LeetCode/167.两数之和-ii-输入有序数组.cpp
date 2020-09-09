/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int min = 0;
        int max = numbers.size() - 1;

        while (min < max)
        {
            int sum = numbers[min] + numbers[max];
            if (sum < target)
                ++min;
            if (sum > target)
                --max;
            if (sum == target)
                break;
        }

        return vector<int>{++min, ++max};
    }
};
// @lc code=end
