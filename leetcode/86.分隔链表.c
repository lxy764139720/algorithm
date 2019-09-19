/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (52.62%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 28.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};*/

struct ListNode *partition(struct ListNode *head, int x)
{
    if (!head || !head->next)
    {
        return head;
    }
    struct ListNode *p1, *p2, *numb;
    numb = malloc(sizeof(struct ListNode));
    numb->next = head;
    p1 = numb;
    p2 = numb;
    while (p2 && p2->next)
    {
        if (p1 == p2)
        {
            if (p1->next->val < x)
            {
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        else
        {
            if (p2->next->val >= x)
            {
                p2 = p2->next;
            }
            else
            {
                struct ListNode *temp = p1->next;
                p1->next = p2->next;
                p2->next = p2->next->next;
                p1->next->next = temp;
                p1 = p1->next;
            }
        }
    }
    return numb->next;
}
