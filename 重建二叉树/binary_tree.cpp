#include <exception>
#include <iostream>
#include <vector>

//定义二叉树结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
  public:
    TreeNode *reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin)
    {
        //得到长度并且判断是否符合要求
        int length = pre.size();
        if (length == 0 || vin.size() != length)
            return nullptr;

        auto pre_iteration = pre.cbegin();
        auto vin_iteration = vin.cbegin();

        TreeNode *root = new TreeNode();
        root->val = *pre_iteration;
        if (length == 1)
        {
            if (*pre_iteration == *vin_iteration)
                return root;
            else
                return nullptr;
        }
        //找到中序遍历的根节点
        while (vin_iteration != vin.cend() && *vin_iteration != root->val)
            vin_iteration++;

        if (vin_iteration == vin.cend() && *vin_iteration != root->val)
            // throw std::exception("Invalid input");
            return nullptr;

        int length_left = vin_iteration - vin.cbegin();

        if (length_left > 0)
        {
            std::vector<int> pre_left(pre_iteration + 1,
                                      pre_iteration + 1 + length_left);
            std::vector<int> vin_left(vin.cbegin(), vin_iteration);
            root->left = reConstructBinaryTree(pre_left, vin_left);
        }
        if (vin_iteration != vin.cend() - 1)
        {
            std::vector<int> pre_right(pre_iteration + length_left + 1, pre.cend());
            std::vector<int> vin_right(vin_iteration + 1, vin.cend());
            root->right = reConstructBinaryTree(pre_right, vin_right);
        }

        return root;
    }
};

int main()
{
    int pre_v[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int vin_v[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    std::vector<int> pre(pre_v, pre_v + 8), vin(vin_v, vin_v + 8);

    TreeNode *result;

    Solution s;
    result = s.reConstructBinaryTree(pre, vin);
    return 1;
}
