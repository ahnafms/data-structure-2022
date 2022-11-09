#include <iostream>
#include <string>
using namespace std;

struct CSList{
    int data;
    CSList *next;
};

CSList *head, *tail, *curr, *newNode, *del, *before;

void initSingleLinkedList(int data){
    head = new CSList();
    head->data = data;
    head->next = NULL;
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
    newNode = new CSList();
	newNode->data = data;
	head->next = newNode;
	tail = newNode;
	tail->next = head;
}

void addLast(int data){
	newNode = new CSList();
	newNode->data = data;
	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
}
void addMiddle(int data, int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi tidak terjangkau" << endl;
    }else if (posisi == 1){
        cout << "Posisi tidak ditengah" << endl;
    }
    else{
        newNode = new CSList();
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
	newNode = new CSList();
	newNode->data = data;
	newNode->next = head;
	tail->next = newNode;
	head = newNode;
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
    addLast(2);
    addLast(4);
    addFront(8);
    addMiddle(9,3);
    display();
}
