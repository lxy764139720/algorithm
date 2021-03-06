/*
 * @lc app=leetcode.cn id=622 lang=c
 *
 * [622] 设计循环队列
 *
 * https://leetcode-cn.com/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (38.78%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    11.9K
 * Total Submissions: 30.8K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于
 * FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 * 
 * 
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 * 
 * 你的实现应该支持如下操作：
 * 
 * 
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
 * 
 * circularQueue.enQueue(1);  // 返回 true
 * 
 * circularQueue.enQueue(2);  // 返回 true
 * 
 * circularQueue.enQueue(3);  // 返回 true
 * 
 * circularQueue.enQueue(4);  // 返回 false，队列已满
 * 
 * circularQueue.Rear();  // 返回 3
 * 
 * circularQueue.isFull();  // 返回 true
 * 
 * circularQueue.deQueue();  // 返回 true
 * 
 * circularQueue.enQueue(4);  // 返回 true
 * 
 * circularQueue.Rear();  // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有的值都在 0 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 * 
 * 
 */

typedef struct
{
    int Capacity;
    int Front;
    int Rear;
    int size;
    int *Array;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue *obj);
bool myCircularQueueIsEmpty(MyCircularQueue *obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue *myCircularQueueCreate(int k)
{
    const int capacity = k;
    MyCircularQueue *q = malloc(sizeof(MyCircularQueue));
    q->Array = calloc(k, sizeof(MyCircularQueue));
    q->Capacity = k;
    q->Front = 0;
    q->Rear = 0;
    q->size = 0;
    return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    else
    {
        obj->Array[obj->Rear] = value;
        ++obj->Rear;
        obj->Rear = obj->Rear % obj->Capacity;
        ++obj->size;
        return true;
    }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    else
    {
        ++obj->Front;
        obj->Front = obj->Front % obj->Capacity;
        --obj->size;
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue *obj)
{
    if (!myCircularQueueIsEmpty(obj))
    {
        return obj->Array[obj->Front];
    }
    else
    {
        return -1;
    }
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue *obj)
{
    int num;
    if (obj->Rear == 0)
    {
        num = obj->Capacity - 1;
    }
    else
    {
        num = obj->Rear - 1;
    }
    if (!myCircularQueueIsEmpty(obj))
    {
        return obj->Array[num];
    }
    else
    {
        return -1;
    }
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return obj->Capacity == obj->size;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->Array);
    obj->Capacity = 0;
    obj->size = 0;
    obj->Front = 0;
    obj->Rear = 0;
    obj->Array = NULL;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
