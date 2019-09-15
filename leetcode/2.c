/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
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
