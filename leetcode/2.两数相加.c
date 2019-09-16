/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.63%)
 * Likes:    3038
 * Dislikes: 0
 * Total Accepted:    208.7K
 * Total Submissions: 585.6K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *l3;
    int carry = 0;
    l3 = malloc(sizeof(struct ListNode));
    struct ListNode *l4 = l3;
    //相加
    while (l1 != NULL || l2 != NULL)
    {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = (a + b + carry) % 10;
        carry = (a + b + carry) / 10;
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->val = sum;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    if (carry != 0)
    {
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->val = 1;
    }
    l3->next = NULL;
    l3 = l4->next;
    free(l4);
    return l3;
}

