#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int* p_start,p_end;
    int a;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* ptr;
    ptr=(MyCircularQueue*) malloc (sizeof(MyCircularQueue)*1000);
    return ptr;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  
}

void myCircularQueueFree(MyCircularQueue* obj) {
    
}

int main(){
    int a;
    scanf("%d",a);
    printf("hello vscode!");
    return 0;
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