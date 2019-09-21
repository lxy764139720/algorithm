/*
 * @lc app=leetcode.cn id=707 lang=c
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Easy (22.85%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 44.6K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 
 * 在链表类中实现这些功能：
 * 
 * 
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 * 
 * 
 
#include <stdio.h>
#include <stdlib.h>*/
typedef struct //ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

typedef struct //MyLinkedLIst
{
    struct ListNode *head;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
    ListNode *numb = malloc(sizeof(ListNode));
    numb->val = -1;
    numb->next = NULL; //哑节点
    MyLinkedList *MyLinkedList = malloc(sizeof(MyLinkedList));
    MyLinkedList->head = numb;
    return MyLinkedList;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0)
    {
        return -1;
    }
    ListNode *head = obj->head->next;
    for (; index > 0 && head; --index)
    {
        head = head->next;
    }
    if (!head)
    {
        return -1;
    }
    return head->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    ListNode *numb = obj->head;
    ListNode *temp = numb->next;
    numb->next = malloc(sizeof(ListNode));
    numb->next->val = val;
    numb->next->next = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    ListNode *p1 = obj->head;
    while (p1->next)
    {
        p1 = p1->next;
    }
    p1->next = malloc(sizeof(ListNode));
    p1->next->val = val;
    p1->next->next = NULL;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index <= 0)
    {
        myLinkedListAddAtHead(obj, val);
    }
    else if (index == 1 && !obj->head->next)
    {
    }
    else
    {
        ListNode *p1 = obj->head;
        for (; index > 0 && p1->next; --index)
        {
            p1 = p1->next;
        }
        ListNode *temp = p1->next;
        p1->next = malloc(sizeof(ListNode));
        p1->next->val = val;
        p1->next->next = temp;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index >= 0)
    {
        ListNode *p1 = obj->head;
        for (; index > 0 && p1->next; --index)
        {
            p1 = p1->next;
        }
        if (p1->next)
        {
            ListNode *temp = p1->next;
            p1->next = temp->next;
            free(temp);
        }
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    ListNode *p1 = obj->head;
    while (p1)
    {
        ListNode *temp = p1;
        p1 = p1->next;
        free(temp);
    }
    free(obj);
}
/*
int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    int param_1 = myLinkedListGet(obj, 0);
    printf("%d\n", param_1);
    myLinkedListAddAtIndex(obj, 1, 2);
    param_1 = myLinkedListGet(obj, 0);
    printf("%d\n", param_1);
    param_1 = myLinkedListGet(obj, 1);
    printf("%d\n", param_1);
    myLinkedListAddAtIndex(obj, 0, 1);
    param_1 = myLinkedListGet(obj, 0);
    printf("%d\n", param_1);
    param_1 = myLinkedListGet(obj, 1);
    printf("%d\n", param_1);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
