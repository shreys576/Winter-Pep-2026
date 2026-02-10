#include<bits/stdc++.h>
using namespace std;


class Queue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int val){
        if(rear == size - 1){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1){
            front++;
        }
        rear++;
        arr[rear] = val;
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > rear){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        if(front == -1 || front > rear){
            return true;
        }
        return false;
    }
};

int main(){


}