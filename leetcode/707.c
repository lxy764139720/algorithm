#include <stdlib.h>
#include <stdio.h>
struct MyLinkedList;
typedef struct MyLinkedList
{
	int val;
	struct MyLinkedList* next;
}MyLinkedList;
MyLinkedList* myLinkedListCreate();
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList** obj, int val);;
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList** obj, int index);
void myLinkedListFree(MyLinkedList** obj);
int myLinkedListLength(MyLinkedList* obj);
int myLinkedListIsEmpty(MyLinkedList* obj);

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate()
{
	MyLinkedList* List = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (List == NULL)
	{
		printf("Out of space!\n");
	}
	else
	{
		List->val = 0;
		List->next = NULL;
	}
	return List;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
	int length = myLinkedListLength(obj);
	if (index >= length) {
		printf("Index out of space!\n");
		return -1;
	}
	else {
		MyLinkedList* Temp = obj;
		for (int i = 0; i < index; ++i)
		{
			Temp = Temp->next;
		}
		return Temp->val;
	}
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList** obj, int val)
{
	MyLinkedList* Temp;
	MyLinkedList* Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (Node == NULL)
	{
		printf("Out of space!\n");
	}
	else
	{
		Node->val = val;
		Temp = *obj;//*obj指示节点实例的地址
		*obj = Node;//head指针指向新节点
		(*obj)->next = Temp;//新节点的next指向原新节点的地址
	}
}
/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
	MyLinkedList* Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (Node!=NULL) {
		Node->val = val;
		Node->next = NULL;
		MyLinkedList* Temp = obj;
		while (Temp->next != NULL)
		{
			Temp = Temp->next;
		}
		Temp->next = Node;
	}
	else {

	}
}


/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) //在指定位置的节点之前插入
{
	int length = myLinkedListLength(obj);
	if (index == 0)
	{
		myLinkedListAddAtHead(&obj, val);
	}
	else if (index == length)
	{
		myLinkedListAddAtTail(obj, val);
	}
	else if (index > length || index < 0)
	{
		printf("Index out of length!\n");
	}
	else
	{
		MyLinkedList* Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
		if (Node != NULL)
		{
			MyLinkedList* Temp = obj;
			for (int i = 1; i < index; ++i)
			{
				Temp = Temp->next;
			}
			Node->val = val;
			Node->next = Temp->next;
			Temp->next = Node;
		}
		else
		{
			printf("Out of space!\n");
		}
	}
}


/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList** obj, int index)
{
	if (myLinkedListIsEmpty(*obj)) {
		printf("You need to create a list first!\n");
		return;
	}
	MyLinkedList* Node, * Temp;
	int length = myLinkedListLength(*obj);
	if (index < 0 || index > length)
	{
		printf("Index out of length!\n");
	}
	else if (index == 0)
	{
		Temp = *obj;
		*obj = Temp->next;
		free(Temp);
	}
	else if (index == length)
	{
		Node = *obj;
		while (Node->next->next != NULL) {
			Node = Node->next;
		}
		free(Node->next);
		Node->next = NULL;
	}
	else
	{
		Node = *obj;
		for (int i = 1; i < index; ++i)
		{
			Node = Node->next;
		}
		Temp = Node->next;
		Node->next = Temp->next;
		free(Temp);
	}
}

void myLinkedListFree(MyLinkedList** obj)
{
	MyLinkedList* Node = *obj;
	MyLinkedList* Temp;
	while (Node != NULL) {
		Temp = Node;
		Node = Node->next;
		free(Temp);
	}
	*obj = NULL;
}

int myLinkedListLength(MyLinkedList* obj)
{
	int length = 0;
	MyLinkedList* Temp = obj;
	while (Temp != NULL)
	{
		++length;
		Temp = Temp->next;
	}
	return length;
}

int myLinkedListIsEmpty(MyLinkedList* obj) {
	return obj == NULL;
}

int main(){
	printf("hello");
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