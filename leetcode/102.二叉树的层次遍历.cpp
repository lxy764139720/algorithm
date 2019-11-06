/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (58.75%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    55K
 * Total Submissions: 92.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> *layerValue = new vector<vector<int>>();
        if (!root)
            return *layerValue;
        queue<TreeNode *> *myQueue = new queue<TreeNode *>();
        myQueue->push(root);
        while (!myQueue->empty())
        {
            vector<int> *innerLayer = new vector<int>();
            int i = myQueue->size();
            while (i > 0)
            {
                innerLayer->push_back(root->val);
                if (root->left)
                    myQueue->push(root->left);
                if (root->right)
                    myQueue->push(root->right);
                myQueue->pop();
                root = myQueue->front();
                --i;
            }
            layerValue->push_back(*innerLayer);
        }
        return *layerValue;
    }
};
// @lc code=end
