/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (67.47%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 51K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
//左右中
//非递归
#define MAX 1000

typedef struct stackPlus
{
    struct TreeNode *stack;
    int flag;
} stackPlus;

typedef struct Stack
{
    stackPlus *stack[MAX];
    int len;
} Stack;

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *back = malloc(sizeof(int) * MAX);
    Stack S;
    S.len = 0;
    int flag = 0;
    while (root || S.len)
    {
        while (root)
        {
            S.stack[S.len]->stack = root;
            S.stack[S.len++]->flag = 0;
            root = root->left;
        }
        if (S.len)
        {
            if (S.stack[S.len - 1]->flag == 0)
            {
                root = S.stack[S.len - 1]->stack->right;
                S.stack[S.len - 1]->flag = 1;
            }
            else
            {
                root = S.stack[--S.len]->stack;
                back[(*returnSize)++] = root->val;
            }
        }
    }
    back[*returnSize] = '\0';
    return back;
}

/*递归
#define MAX 1000

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *back = malloc(sizeof(int) * MAX);
    *returnSize = 0;
    loop(root, back, returnSize);
    return back;
}

void loop(struct TreeNode *root, int *back, int *returnSize)
{
    if (root)
    {
        loop(root->left, back, returnSize);
        loop(root->right, back, returnSize);
        back[(*returnSize)++] = root->val;
    }
}
*/

// @lc code=end
