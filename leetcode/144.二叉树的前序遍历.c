/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (61.67%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    45.2K
 * Total Submissions: 72.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
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
//中左右
#define MAX 1000

typedef struct Stack
{
    struct TreeNode *stack[MAX];
    int len;
} Stack;

//非递归
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *back = malloc(sizeof(int) * MAX);
    Stack S; //这种写法即已分配存储空间
    S.len = 0;
    while (root || S.len)//节点非空或栈非空
    {
        while (root)//节点非空
        {
            back[(*returnSize)++] = root->val;//直接返回
            S.stack[S.len++] = root;//然后入栈
            root = root->left;//访问左节点
        }
        if (S.len)//栈非空
        {
            root = S.stack[--S.len];//退回父节点
            root = root->right;//进入右节点
        }
    }
    back[*returnSize] = '\0';
    return back;
}

/*递归
void loop(struct TreeNode *root, int *back, int *returnSize)
{
    if (root)
    {
        back[(*returnSize)++] = root->val; //注意++在后，后自增
        loop(root->left, back, returnSize);
        loop(root->right, back, returnSize);
    }
    back[*returnSize] = '\0'; //字符数组结束
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *back = malloc(sizeof(int) * MAX);
    loop(root, back, returnSize);
    return back;
}
*/

// @lc code=end
