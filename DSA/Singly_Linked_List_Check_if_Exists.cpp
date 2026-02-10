#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

void InsertAtStart(Node* &head, int value){
    Node* newnode = new Node(value);
    Node* temp = head;
    head = newnode;
    newnode -> next = temp;
}

void InsertAtEnd(Node* &head, int value){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    Node* newnode = new Node(value);
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    temp -> next = newnode;

}

void InsertAfterKey(Node* &head, int value, int key){
    Node* newnode = new Node(value);
    Node* temp = head;
    while(temp != nullptr && temp -> data != key){
        temp = temp -> next;
    }

    if(temp == nullptr){
        InsertAtEnd(head, value);
        return;
    }
    Node* temp2 = temp -> next;
    temp -> next = newnode;
    newnode -> next = temp2;
}

void InsertBeforeKey(Node* &head, int value, int key){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    Node* newnode = new Node(value);
    if(head -> data == key){
        InsertAtStart(head, value);
        return;
    }
    Node* temp = head;
    while(temp -> next != nullptr && temp -> next -> data != key){
        temp = temp -> next;
    }
    if(temp -> next == nullptr){
        InsertAtEnd(head, value);
        return;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void InsertAtPoint(Node* &head, int value, int point){
    if(head == nullptr){
        InsertAtStart(head, value);
        return;
    }
    if(point == 1){
        InsertAtStart(head, value);
    }
    Node* temp = head;
    for(int i = 1; i < point - 1; i++){
        if(temp -> next == nullptr){
            InsertAtEnd(head, value);
            return;
        }
        temp = temp -> next;
    }
    if(temp -> next == nullptr){
        InsertAtEnd(head, value);
        return;
    }
    Node* newnode = new Node(value);
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void DeleteAtStart(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* toDelete = head;
    head = head -> next;
    delete toDelete;
}

void DeleteAtEnd(Node* &head){
    if(head == nullptr){
        return;
    }
    if(head -> next == nullptr){
        DeleteAtStart(head);
        return;
    }
    Node* temp = head;
    while(temp -> next -> next != nullptr){
        temp = temp -> next;
    }
    Node* toDelete = temp -> next;
    temp -> next = nullptr;
    delete toDelete;
}

void DeleteValue(Node* &head, int value){
    if(head == nullptr){
        return;
    }
    if(head -> data == value){
        DeleteAtStart(head);
        return;
    }
    Node* temp = head;
    while(temp -> next != nullptr && temp -> next -> data != value){
        temp = temp -> next;
    }
    if(temp -> next == nullptr){
        return;
    }
    Node* toDelete = temp -> next;
    temp -> next = toDelete -> next;
    delete toDelete;
}

void DeleteAtPosition(Node* &head, int position){
    if(head == nullptr){
        return;
    }
    if(position == 1){
        DeleteAtStart(head);
    }
    Node* temp = head;
    for(int i = 1; i < position - 1; i ++){
        if(temp -> next != nullptr){
            temp = temp -> next;
        }
    }
    if(temp -> next == nullptr){
        return;
    }
    Node* toDelete = temp -> next;
    temp -> next = toDelete -> next;
    delete toDelete;
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

bool SearchKey(Node* head, int key){
    if(head == nullptr) return false;

    if(head -> data == key) return true;

    SearchKey(head -> next, key);
}


int main(){

    Node* head = nullptr;
    InsertAtEnd(head, 5);
    InsertAtStart(head, 3);
    InsertAfterKey(head, 4, 3);
    InsertBeforeKey(head, 1, 5);
    InsertAfterKey(head, 7, 4);
    InsertAtStart(head, 12);
    InsertBeforeKey(head, 8, 4);
    InsertAtPoint(head, 19, 3);
    InsertAtEnd(head, 8);
    cout << SearchKey(head,67);
}