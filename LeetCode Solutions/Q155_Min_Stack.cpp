#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> s1;
    stack<int> s2;
    MinStack() {
        s2.push(INT_MAX);
    }
    
    void push(int val) {
        s1.push(val);
        s2.push(min(val,s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack st;

    cout << "===== Test Case 1 =====\n";
    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "getMin() = " << st.getMin() << " (Expected: -3)\n";

    st.pop();

    cout << "top() = " << st.top() << " (Expected: 0)\n";
    cout << "getMin() = " << st.getMin() << " (Expected: -2)\n\n";


    cout << "===== Test Case 2 =====\n";
    MinStack st2;

    st2.push(5);
    st2.push(3);
    st2.push(7);
    st2.push(2);

    cout << "getMin() = " << st2.getMin() << " (Expected: 2)\n";

    st2.pop(); // removes 2
    cout << "getMin() = " << st2.getMin() << " (Expected: 3)\n";

    st2.pop(); // removes 7
    cout << "top() = " << st2.top() << " (Expected: 3)\n";
    cout << "getMin() = " << st2.getMin() << " (Expected: 3)\n\n";


    cout << "===== Test Case 3 (Single Element) =====\n";
    MinStack st3;
    st3.push(10);

    cout << "top() = " << st3.top() << " (Expected: 10)\n";
    cout << "getMin() = " << st3.getMin() << " (Expected: 10)\n";

    st3.pop();
    cout << "Popped last element.\n";
    cout << "(Now stack is empty, calling top/getMin would crash)\n\n";


    cout << "===== Test Case 4 (Duplicates) =====\n";
    MinStack st4;
    st4.push(4);
    st4.push(4);
    st4.push(4);

    cout << "getMin() = " << st4.getMin() << " (Expected: 4)\n";

    st4.pop();
    cout << "getMin() = " << st4.getMin() << " (Expected: 4)\n";

    return 0;
}
