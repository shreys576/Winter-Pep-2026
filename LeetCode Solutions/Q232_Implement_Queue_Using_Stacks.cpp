#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue q;

    cout << "===== Test Case 1 (LeetCode Standard Example) =====\n";
    q.push(1);
    q.push(2);

    cout << "peek() = " << q.peek() << " (Expected: 1)\n";
    cout << "pop() = " << q.pop() << " (Expected: 1)\n";
    cout << "empty() = " << q.empty() << " (Expected: 0)\n\n";


    cout << "===== Test Case 2 =====\n";
    q.push(3);
    q.push(4);

    cout << "peek() = " << q.peek() << " (Expected: 2)\n";
    cout << "pop() = " << q.pop() << " (Expected: 2)\n";
    cout << "pop() = " << q.pop() << " (Expected: 3)\n";
    cout << "peek() = " << q.peek() << " (Expected: 4)\n";
    cout << "empty() = " << q.empty() << " (Expected: 0)\n\n";


    cout << "===== Test Case 3 (Single Element) =====\n";
    MyQueue q2;
    q2.push(10);

    cout << "peek() = " << q2.peek() << " (Expected: 10)\n";
    cout << "pop() = " << q2.pop() << " (Expected: 10)\n";
    cout << "empty() = " << q2.empty() << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 (Multiple Operations) =====\n";
    MyQueue q3;

    q3.push(5);
    q3.push(6);
    q3.push(7);

    cout << "pop() = " << q3.pop() << " (Expected: 5)\n";
    cout << "peek() = " << q3.peek() << " (Expected: 6)\n";

    q3.push(8);

    cout << "pop() = " << q3.pop() << " (Expected: 6)\n";
    cout << "pop() = " << q3.pop() << " (Expected: 7)\n";
    cout << "pop() = " << q3.pop() << " (Expected: 8)\n";
    cout << "empty() = " << q3.empty() << " (Expected: 1)\n\n";

    return 0;
}
