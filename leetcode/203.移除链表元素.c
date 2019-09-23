/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.29%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    39K
 * Total Submissions: 92.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeElements(struct ListNode *head, int val)
{
    while (head && head->val == val)
    {
        head = head->next;
    }
    if (!head)
    {
        return head;
    }
    struct ListNode *p1 = head;
    while (p1->next)
    {
        if (p1->next->val == val)
        {
            p1->next = p1->next->next;
        }
        else
        {
            p1 = p1->next;
        }
    }
    if (p1->val == val)
    {
        p1 = NULL;
    }
    return head;
}
