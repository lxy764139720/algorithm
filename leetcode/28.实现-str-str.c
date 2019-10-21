/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (38.88%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    90.2K
 * Total Submissions: 231.3K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start

int *calNext(char *needle)
{
    int size = 0;
    int i = 0;
    int j = -1;
    for (; needle[size]; ++size)
        ;
    int *next = malloc(sizeof(int) * size);
    next[0] = -1;
    while (i < size - 1)
    {
        if (j < 0 || needle[i] == needle[j])
        {
            ++i;
            ++j;
            next[i] = needle[i] != needle[j] ? j : next[j];
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}

int strStr(char *haystack, char *needle)
{
    if (needle[0] == NULL)
    {
        return 0;
    }
    if (haystack[0] == NULL)
    {
        return -1;
    }
    int i = 0;
    int j = 0;
    int *next = calNext(needle);
    while (j == -1 || haystack[i] && needle[j])
    {
        if (j < 0 || haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (!needle[j])
    {
        return i - j;
    }
    return -1;
}

// @lc code=end
