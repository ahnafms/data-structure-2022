#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama,nrp;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *curr, *newNode, *del, *before;

void initSingleLinkedList(string nama, string nrp){
    head = new Mahasiswa();
    head->nama = nama;
    head->nrp = nrp;
    head->next = NULL;
    tail = head;
}

int countSingleLinkedList(){
    curr = head;
    int count = 0;
    while(curr!=NULL){
        count++;
        curr = curr->next;
    }
    return count;
}
void addFirst(string nama, string nrp){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nrp = nrp;
    newNode->next = head;
    head = newNode;
}

void addMiddle(string nama, string nrp, int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi tidak terjangkau" << endl;
    }else if (posisi == 1){
        cout << "Posisi tidak ditengah" << endl;
    }
    else{
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nrp = nrp;
        
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

void addLast(string nama, string nrp){
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nrp = nrp;
    tail->next = newNode;
    tail = newNode;
}

void updateFirst(string nama, string nrp){
    head->nama = nama;
    head->nrp = nrp;
}

void updateMiddle(string nama, string nrp, int posisi){
    curr=head;
    int idx=1;
    while(idx < posisi--){
        curr = curr->next;
        idx++;
    }
    curr->nama = nama;
    curr->nrp = nrp;
}

void updateLast(string nama, string nrp){
    tail->nama = nama;
    tail->nrp = nrp;
}

void deleteFirst(){
    del = head;
    head = head->next;
    delete del;
}

void deleteMiddle(int posisi){
    if(posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi tidak terjangkau" << endl;
    }else if (posisi == 1){
        cout << "Posisi tidak ditengah" << endl;
    }
    else{
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
void deleteLast(){
    curr = head;
    del = tail;
    while(curr->next != tail){
        curr = curr->next;
    }
    tail = curr;
    tail->next = NULL;
    delete (del);
    
}
void display(){
    curr = head;
    while(curr!=NULL){
        cout << curr->nama << " " << curr->nrp << endl;
        curr = curr->next;
    }
}
int main(){
    cout << "\nInitiate Single Linked List" << endl;
    initSingleLinkedList("Ahnaf Musyafa", "038");
    display();
    
    cout << "\nAdd First" << endl;
    addFirst("Reynold Putra", "035");
    display();
    
    cout << "\nAdd Last" << endl;
    addLast("Mohammad Rifki", "011");
    display();
    
    cout << "\nDelete First" << endl;
    deleteFirst();
    display();
    
    cout << "\nAdd Last" << endl;
    addLast("Mad Dog", "012");
    display();
    
    cout << "\nDelete Last" << endl;
    deleteLast();
    display();
    
    cout << "\nChange First" << endl;
    updateFirst("John Lennon", "092");
    display();

    cout << "\nAdd Middle" << endl;
    addMiddle("Chandra Irawan", "031", 2);
    display();

    cout << "\nAdd Middle" << endl;
    addMiddle("Fifi Suhadi", "039", 2);
    display();

    cout << "\nDelete Middle" << endl;
    deleteMiddle(4);
    display();


    cout << "\nChange Middle" << endl;
    updateMiddle("Andrew Tate", "044", 3);
    display();  
}