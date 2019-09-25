/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (50.05%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 90.6K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 
#include <stdio.h>
#include <stdlib.h>
*/
typedef struct //Node
{
    int val;
    struct Node *next;
} Node;

typedef struct //MinStack
{
    struct Node *helpHead;
    struct Node *mainHead;
} MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate()
{
    MinStack *myStack = malloc(sizeof(MinStack));
    myStack->mainHead = NULL;
    myStack->helpHead = NULL;
}

void minStackPush(MinStack *obj, int x)
{
    Node *temp = obj->mainHead;
    obj->mainHead = malloc(sizeof(Node));
    obj->mainHead->val = x;
    obj->mainHead->next = temp;
    if (!obj->helpHead)
    {
        obj->helpHead = malloc(sizeof(Node));
        obj->helpHead->val = x;
        obj->helpHead->next = NULL;
    }
    else
    {
        if (x <= obj->helpHead->val)
        {
            temp = obj->helpHead;
            obj->helpHead = malloc(sizeof(Node));
            obj->helpHead->val = x;
            obj->helpHead->next = temp;
        }
    }
}

void minStackPop(MinStack *obj)
{
    if (!obj->mainHead)
    {
        return;
    }
    if (obj->helpHead->val == obj->mainHead->val)
    {
        obj->helpHead = obj->helpHead->next;
    }
    obj->mainHead = obj->mainHead->next;
}

int minStackTop(MinStack *obj)
{
    if (obj->mainHead)
    {
        return obj->mainHead->val;
    }
    else
    {
        return -1;
    }
}

int minStackGetMin(MinStack *obj)
{
    if (obj->helpHead)
    {
        return obj->helpHead->val;
    }
    else
    {
        return -1;
    }
}

void minStackFree(MinStack *obj)
{
    obj->helpHead = NULL;
    obj->mainHead = NULL;
}

/*
int main()
{
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    int param_3 = minStackGetMin(obj);
    minStackPop(obj);
    int param_4 = minStackTop(obj);
    int param_5 = minStackGetMin(obj);
    minStackFree(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
