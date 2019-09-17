/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (62.23%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    40.5K
 * Total Submissions: 65.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    struct ListNode *newHead, *p, *q;
    newHead = head->next;
    p = head;
    while (p)
    {
        q = p->next->next;
        p->next->next = p;
        if (!q)
        {
            p->next = NULL;
            break;
        }
        if (q->next)
        {
            p->next = q->next;
        }
        else
        {
            p->next = q;
            break;
        }
        p = q;
    }
    return newHead;
}
