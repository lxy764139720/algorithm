/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (64.30%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 31.6K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
/*#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int inorderLen = inorder.size();
        if (inorderLen == 0)
        {
            return NULL;
        }
        int root = postorder.back();
        TreeNode* tree=new TreeNode(root);
        if (inorderLen == 1)
        {
            return tree;
        }
        int rootLocation;
        for (int i = 0; i < inorder.size(); ++i)
        {
            if (inorder[i] == root)
            {
                rootLocation = i;
                break;
            }
        }
        int leftEnd = rootLocation - 1;
        int rightStart = rootLocation + 1;
        vector<int> *newLeftInorder = new vector<int>(inorder.begin(), inorder.begin() + rootLocation);
        vector<int> *newLeftPostorder = new vector<int>(postorder.begin(), postorder.begin() + rootLocation);
        vector<int> *newRightInorder = new vector<int>(inorder.begin() + rootLocation + 1, inorder.end());
        vector<int> *newRightPostorder = new vector<int>(postorder.begin() + rootLocation, postorder.end() - 1);
        tree->left = buildTree(*newLeftInorder, *newLeftPostorder);
        tree->right = buildTree(*newRightInorder, *newRightPostorder);
        return tree;
    }
};
// @lc code=end
