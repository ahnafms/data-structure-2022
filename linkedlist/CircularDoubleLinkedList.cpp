#include <iostream>
#include <string>
using namespace std;

struct CDList{
    int data;
    CDList *next;
    CDList *prev;
};

CDList *head, *tail, *curr, *newNode, *del, *before;

void initSingleLinkedList(int data){
    head = new CDList();
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

int countSingleLinkedList(){
    curr = head;
    int count = 0;
    while(curr->next != head){
        count++;
        curr = curr->next;
    }
    count++;
    return count;
}
void addFirst(int data){
    newNode = new CDList();
	newNode->data = data;
	newNode->next = head;
	head->next = newNode;
	head->prev = newNode;
	tail = head;
	head = newNode;
	head->prev = tail;
}

void addLast(int data){
	newNode = new CDList();
	newNode->data = data;
	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
	head->prev = tail;
}
void addMiddle(int data, int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi tidak terjangkau" << endl;
    }else if (posisi == 1){
        cout << "Posisi tidak ditengah" << endl;
    }
    else{
        newNode = new CDList();
        newNode->data = data;
        curr = head;
        int idx=1;
        while(idx < posisi - 1){
            curr = curr->next;
            idx++;
        }
    	newNode->next = curr->next;
    	curr->next = newNode;
    }
}
void addFront(int data){
	newNode = new CDList();
	newNode->data = data;
	newNode->next = head;
	head->prev = newNode;
	tail->next = newNode;
	head = newNode;
	head->prev = tail;
}

void display (){
	
	curr = head;
	while(true){
		cout << curr->data << " ";
		if(curr->next == head){
			break;
		}
		curr = curr->next;
	}
	cout << endl;
}

int main(){
    initSingleLinkedList(1);
    addFirst(5);
    display();
    addLast(2);
    display();
    addLast(4);
    display();
    addFront(8);
    display();
    addMiddle(9,3);
    display();
}
