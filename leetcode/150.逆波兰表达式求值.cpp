/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (46.18%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 34.7K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 * 
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 
 * 说明：
 * 
 * 
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 
 * 
 * 示例 1：
 * 
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        if (tokens.size() == 0)
            return 0;
        stack<int> numStack;
        int i = 0;
        int fir, last;
        while (i < tokens.size())
        {
            if (tokens[i] == "+")
            {
                last = numStack.top();
                numStack.pop();
                fir = numStack.top();
                numStack.pop();
                numStack.push(fir + last);
            }
            else if (tokens[i] == "-")
            {
                last = numStack.top();
                numStack.pop();
                fir = numStack.top();
                numStack.pop();
                numStack.push(fir - last);
            }
            else if (tokens[i] == "*")
            {
                last = numStack.top();
                numStack.pop();
                fir = numStack.top();
                numStack.pop();
                numStack.push(fir * last);
            }
            else if (tokens[i] == "/")
            {
                last = numStack.top();
                numStack.pop();
                fir = numStack.top();
                numStack.pop();
                numStack.push(fir / last);
            }
            else
            {
                numStack.push(atoi(tokens[i].c_str()));
            }
            ++i;
        }
        return numStack.top();
    }
};
// @lc code=end
