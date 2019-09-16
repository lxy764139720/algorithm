/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (57.27%)
 * Likes:    626
 * Dislikes: 0
 * Total Accepted:    111.5K
 * Total Submissions: 194.7K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
/*#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};*/

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    struct ListNode *l4 = l3;
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    else
    {
        while (l1 && l2)
        {
            l3->next = malloc(sizeof(struct ListNode));
            l3 = l3->next;
            if (l1->val > l2->val)
            {
                l3->val = l2->val;
                l2 = l2 ? l2->next : NULL;
            }
            else
            {
                l3->val = l1->val;
                l1 = l1 ? l1->next : NULL;
            }
        }
        l3->next = l1 ? l1 : l2;
    }
    return l4->next;
}
