/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.75%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 94.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    struct ListNode *p1;
    p1 = head;
    while (p1 && p1->next)
    {
        if (p1->next->val == p1->val)
        {
            struct ListNode *temp = p1->next;
            p1->next = temp->next;
            free(temp);
        }
        else
        {
            p1 = p1->next;
        }
    }
    return head;
}
