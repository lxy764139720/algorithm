/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (39.00%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 65.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (!head)
    {
        return head;
    }
    struct ListNode *Head = head;
    struct ListNode *l1 = head;
    int sum = 0;
    while (l1->next)
    {
        l1 = l1->next;
        ++sum;
    }
    ++sum;
    l1->next = Head;
    sum = sum - (k % sum);
    while (sum > 0)
    {
        Head = Head->next;
        l1 = l1->next;
        --sum;
    }
    l1->next = NULL;
    return Head;
}
