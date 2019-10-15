/*
 * @lc app=leetcode.cn id=498 lang=c
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (38.84%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 17.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 输出:  [1,2,4,7,5,3,6,8,9]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 给定矩阵中的元素总数不会超过 100000 。
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDiagonalOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrixSize == 0 || *matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int row = matrixSize;
    int col = matrixColSize[0];
    *returnSize = col * row;
    int *returnMatrix = malloc(*returnSize * sizeof(int));
    int x, y, index, flag;
    index = 0;
    flag = 0;
    for (int time = 0; time < col + row; ++time)
    {
        y = time >= (flag == 0 ? row : col) ? (flag == 0 ? row : col) - 1 : time;
        x = time - y;
        for (; x < (flag == 0 ? col : row) && y >= 0; ++x, --y)
        {
            returnMatrix[index] = flag == 0 ? matrix[y][x] : matrix[x][y];
            ++index;
        }
        flag = flag == 0 ? 1 : 0;
    }
    return returnMatrix;
}

// @lc code=end
