#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void InsertAtStart(Node* &head, int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        return;
    }
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
}

void InsertAtEnd(Node* &head, int value){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    Node* newnode = new Node(value);
    newnode -> prev = temp;
    temp -> next = newnode;
}

void InsertAtPoint(Node* &head, int value, int point){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    if(point == 1){
        InsertAtStart(head, value);
        return;
    }
    Node* temp = head;
    for(int i = 1; i < point; i++){
        if(temp -> next == nullptr){
            InsertAtEnd(head, value);
            return;
        }
        temp = temp -> next;
    }
    Node* newnode = new Node(value);
    newnode -> next = temp;
    newnode -> prev = temp -> prev;
    temp -> prev -> next = newnode;
    temp -> prev = newnode;
}


void DeleteFirst(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* toDelete = head;
    head = head -> next;
    if(head != nullptr){
        head -> prev = nullptr;
    }
    delete toDelete;
}

void DeleteLast(Node* &head){
    if(head == nullptr){
        return;
    }
    if(head -> next == nullptr){
        DeleteFirst(head);
        return;
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    Node* toDelete = temp;
    temp -> prev -> next = nullptr;
    delete toDelete;
}

void DeleteElement(Node* head, int value){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    while(temp -> next != nullptr && temp -> data != value){
        if(temp -> next == nullptr){
            return;
        }
        temp = temp -> next;
    }
    if(temp -> next == nullptr){
        return;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    delete temp; 
}

void PrintList(Node* head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){

    Node* head = nullptr;

    InsertAtStart(head, 3);
    PrintList(head);

    InsertAtEnd(head, 5);
    PrintList(head);

    InsertAtStart(head, 7);
    PrintList(head);

    InsertAtPoint(head, 9, 2);
    PrintList(head);

    InsertAtPoint(head, 69, 3);
    PrintList(head);

    InsertAtPoint(head, 1, 7);
    PrintList(head); 
    
    DeleteElement(head, 69);
    PrintList(head);
}