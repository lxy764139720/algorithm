/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (55.58%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 26.9K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> newv;
        stack<int> news;
        int i, now, k, next, p = 0;
        for (i = 0; i < T.size(); ++i)
        {
            now = T.at(i);
            for (k = i + 1; k < T.size(); ++k)
            {
                next = T.at(k);
                if (now < next)
                {
                    while (!news.empty())
                    {
                        ++p;
                        news.pop();
                    }
                    ++p;
                    break;
                }
                else
                {
                    news.push(next);
                }
            }
            newv.push_back(p);
            p = 0;
            while (!news.empty())
            {
                news.pop();
            }
        }
        return newv;
    }
};
// @lc code=end
