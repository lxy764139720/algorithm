/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (43.75%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 41.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    struct ListNode *p1, *p2;
    p1 = head;
    p2 = head;
    while (p1 && p1->next)
    {
        while (p2 != p1->next)
        {
            if (p1->next->val == p2->val)
            {
                struct ListNode *temp = p1->next;
                p1->next = temp->next;
                free(temp);
                break;
            }
            p2 = p2->next;
        }
        p2 = head;
        p1 = p1->next;
    }
    return head;
}
