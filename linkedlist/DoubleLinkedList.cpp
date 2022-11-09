#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} List;

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && \
            list->_tail == NULL);
}

void dlist_pushFront(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }
        newNode->next = list->_head;
        list->_head->prev = newNode;
        list->_head = newNode;
    }
}

void dlist_pushBack(List *list, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}
	
void dlist_pushMiddle(List *list, unsigned index, int value){
        DListNode *newNode = __dlist_createNode(value);
        if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }
        DListNode* curr;
        curr = list->_head;
        int idx = 1;
		while(idx<index-1){
            curr = curr->next;
            idx++;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
    	}
    }

void printLS (List *list){
	DListNode* curr;
	curr = list->_head;
	while(true){
		cout << curr->data << " ";
		if(curr->next == NULL){
			break;
		}
		curr = curr->next;
	}
	cout << endl;
}
#include <stdio.h>

int main()
{
    List myList;

    dlist_init(&myList);

    dlist_pushBack(&myList, 1);
    dlist_pushBack(&myList, 2);
    dlist_pushBack(&myList, 3);
    dlist_pushBack(&myList, 4);
 	printLS(&myList);
    dlist_pushFront(&myList, 10);
    dlist_pushFront(&myList, 9);
    dlist_pushFront(&myList, 8);
    dlist_pushFront(&myList, 7);
	 printLS(&myList);
    dlist_pushMiddle(&myList, 3, 1);
    printLS(&myList);
    return 0;
}
