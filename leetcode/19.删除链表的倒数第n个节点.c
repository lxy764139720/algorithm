/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dumb = malloc(sizeof(struct ListNode));
    dumb->next = head;
    struct ListNode *l1, *l2;
    l1 = dumb;
    l2 = dumb;
    for (int ahead = n + 1; ahead > 0; --ahead)
    {
        l2 = l2->next;
    }
    while (l2 != NULL)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    l1->next = l1->next ? l1->next->next : NULL;
    return dumb->next;
}
