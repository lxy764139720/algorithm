/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.92%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    68.4K
 * Total Submissions: 99.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000

void loop(struct TreeNode *root, int *back, int *returnSize)
{
    if (root)
    {
        loop(root->left, back, returnSize);
        back[(*returnSize)++] = root->val; //注意++在后，后自增
        loop(root->right, back, returnSize);
    }
    back[*returnSize] = '\0'; //字符数组结束
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *back = malloc(sizeof(int) * MAX);
    loop(root, back, returnSize);
    return back;
}

// @lc code=end
