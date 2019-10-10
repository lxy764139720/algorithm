/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.84%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    82.4K
 * Total Submissions: 200.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    digits[digitsSize - 1] = (digits[digitsSize - 1] + 1) % 10;
    if (digits[digitsSize - 1] != 0)
    {
        *returnSize = digitsSize;
        return digits;
    }
    int carry = 1;
    int flag = 0;
    for (int i = digitsSize - 2; i >= 0; --i)
    {
        flag = digits[i] == 9 && carry == 1 ? 1 : 0;
        digits[i] = (digits[i] + carry) % 10;
        carry = flag == 1 ? 1 : 0;
    }
    *returnSize = digitsSize;
    if (carry == 1)
    {
        int *newDigits = (int *)malloc((digitsSize + 1) * sizeof(int));
        for (; digitsSize > 0; --digitsSize)
        {
            newDigits[digitsSize] = digits[digitsSize - 1];
        }
        newDigits[0] = 1;
        ++(*returnSize);
        return newDigits;
    }
    return digits;
}

// @lc code=end
