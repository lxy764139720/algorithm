/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.58%)
 * Likes:    1092
 * Dislikes: 0
 * Total Accepted:    130.4K
 * Total Submissions: 328.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 0)
        {
            return true;
        }
        stack<char> mystack;
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s.at(i);
            if (c == '(' || c == '[' || c == '{')
            {
                mystack.push(c);
            }
            else
            {
                if (mystack.empty())
                {
                    return false;
                }
                else if (mystack.top() == '(' && c == ')' || mystack.top() == '[' && c == ']' || mystack.top() == '{' && c == '}')
                {
                    mystack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (mystack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
