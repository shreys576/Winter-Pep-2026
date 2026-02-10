#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
    public:
    Node* top;

    Stack(){
        top = NULL;
    }

    void push(int val){
        Node* newnode = new Node(val);
        if(top == NULL){
            top = newnode;
            return;
        }
        newnode -> next = top;
        top = newnode;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return;
        }
        Node* toDelete = top;
        top = top -> next;
        delete toDelete;
    }

    int peek(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top -> data;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void print(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return;
        }
        Node* temp = top;
        while(temp != NULL){
            cout << temp-> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main(){

    Stack st;
    st.push(3);
    st.push(5);
    st.print();

    st.pop();
    st.peek();
    st.push(1);
    st.push(4);
    st.push(9);
    st.push(0);
    st.push(7);
    st.print();

}