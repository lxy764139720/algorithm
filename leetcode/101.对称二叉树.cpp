/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.47%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    67.1K
 * Total Submissions: 137.1K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return compare(root->left, root->right);
    }
    bool compare(TreeNode *temp1, TreeNode *temp2)
    {
        if (!temp1 && !temp2)
            return true;
        if (!temp1 || !temp2)
            return false;
        return (temp1->val == temp2->val) && compare(temp1->left, temp2->right) && compare(temp2->left, temp1->right);
    }
};
// @lc code=end
