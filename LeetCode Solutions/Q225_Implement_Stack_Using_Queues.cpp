#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack st;

    cout << "===== Test Case 1 (LeetCode Standard Example) =====\n";
    st.push(1);
    st.push(2);

    cout << "top() = " << st.top() << " (Expected: 2)\n";
    cout << "pop() = " << st.pop() << " (Expected: 2)\n";
    cout << "empty() = " << st.empty() << " (Expected: 0)\n\n";


    cout << "===== Test Case 2 =====\n";
    st.push(3);
    st.push(4);

    cout << "top() = " << st.top() << " (Expected: 4)\n";
    cout << "pop() = " << st.pop() << " (Expected: 4)\n";
    cout << "pop() = " << st.pop() << " (Expected: 3)\n";
    cout << "pop() = " << st.pop() << " (Expected: 1)\n";
    cout << "empty() = " << st.empty() << " (Expected: 1)\n\n";


    cout << "===== Test Case 3 (Single Push-Pop) =====\n";
    MyStack st2;
    st2.push(10);

    cout << "top() = " << st2.top() << " (Expected: 10)\n";
    cout << "pop() = " << st2.pop() << " (Expected: 10)\n";
    cout << "empty() = " << st2.empty() << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 (Multiple Operations) =====\n";
    MyStack st3;

    st3.push(5);
    st3.push(6);
    st3.push(7);

    cout << "pop() = " << st3.pop() << " (Expected: 7)\n";
    cout << "top() = " << st3.top() << " (Expected: 6)\n";

    st3.push(8);

    cout << "top() = " << st3.top() << " (Expected: 8)\n";
    cout << "pop() = " << st3.pop() << " (Expected: 8)\n";
    cout << "pop() = " << st3.pop() << " (Expected: 6)\n";
    cout << "pop() = " << st3.pop() << " (Expected: 5)\n";
    cout << "empty() = " << st3.empty() << " (Expected: 1)\n\n";

    return 0;
}
