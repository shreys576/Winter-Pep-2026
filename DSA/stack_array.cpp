#include<bits/stdc++.h>
using namespace std;


class Stack{
    int top;
    int size;
    int* arr;
    public:
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int x){
        if(top == size - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else if(top > size - 1){
            cout << "Stack Overflow" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top < 0;
    }
    void print(){
        if(top < 0){
            cout << "Stack is Empty" << endl;
        }
        else{
            for(int i = top; i >= 0; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


int main(){

    Stack st(5);
    st.push(1);
    st.print();

    st.push(2);
    st.push(4);
    st.print();

    st.pop();
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.print();

    cout << st.peek() << endl;

}