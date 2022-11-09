#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
struct store{
	int urutan;
	char nama[100];
};
// Node Structure
struct QueueNode {
    int urutan;
    char nama[100];
    QueueNode *next;
};

/* Structure of Queue using List */
struct Queue
{
    QueueNode *_front, *_rear;
    unsigned _size;

    void init()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(int value, char nama[])
    {
        QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            newNode->urutan = value;
            newNode->next = NULL;
            strcpy(newNode->nama, nama);
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    store front()
    {
        store temp;
		if (!isEmpty()){	
			strcpy(temp.nama, _front->nama);
			temp.urutan = _front->urutan;
			return temp;
		}
		else return temp;
    }

    unsigned size() {
        return _size;
    }
};

int main(int argc, char const *argv[])
{
    // Buat objek queue
    Queue cs;
    Queue teller;
    store temp;
    // PENTING!! Jangan lupa di-init()
    cs.init();
    teller.init();
	while(1){
		char nama[100];
		int antrian;
		cout << "nama\n";
		cin >> nama;
		cout << "press 0 to queue CS and press 1 to queue Teller press 2 to end\n";
		cin >> antrian;
		if(antrian > 1) break;
		else if(antrian == 0) cs.push(cs._size + 1, nama);
		else if(antrian == 1) teller.push(teller._size + 1, nama);
	}
	
    // Cetak isi queue
    cout << "\nAntrian CS\n";
    while (!cs.isEmpty()) {
    	temp = cs.front();
    	cout << "\nUrutan : ";
		cout << temp.urutan;
		cout << "\nNama: ";
		cout << temp.nama << "\n";
		cs.pop();
    }
    
    cout << "\nAntrian Teller\n";
    while (!teller.isEmpty()){
		temp = teller.front();
		cout << "Urutan : ";
		cout << temp.urutan;
		cout << "\nNama: ";
		cout << temp.nama << "\n";
		teller.pop();
	}
    return 0;
}
