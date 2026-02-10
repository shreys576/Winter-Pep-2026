#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
  
    void deleteandadd(stack<int>& st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        deleteandadd(st, x);
        st.push(temp);
    }
    
    stack<int> insertAtBottom(stack<int> &st, int x) {
        deleteandadd(st, x);
        return st;
    }
};

// Helper function to print stack (without destroying original)
void printStack(stack<int> st) {
    cout << "Top -> ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "<- Bottom\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);

    cout << "Original Stack:\n";
    printStack(st1);

    int x1 = 99;
    cout << "Insert at Bottom: " << x1 << endl;

    sol.insertAtBottom(st1, x1);

    cout << "Modified Stack:\n";
    printStack(st1);
    cout << "Expected Bottom = 99\n\n";


    cout << "===== Test Case 2 =====\n";
    stack<int> st2;
    st2.push(10);
    st2.push(20);

    cout << "Original Stack:\n";
    printStack(st2);

    int x2 = 5;
    cout << "Insert at Bottom: " << x2 << endl;

    sol.insertAtBottom(st2, x2);

    cout << "Modified Stack:\n";
    printStack(st2);
    cout << "Expected Bottom = 5\n\n";


    cout << "===== Test Case 3 (Empty Stack) =====\n";
    stack<int> st3;

    cout << "Original Stack:\n";
    printStack(st3);

    int x3 = 100;
    cout << "Insert at Bottom: " << x3 << endl;

    sol.insertAtBottom(st3, x3);

    cout << "Modified Stack:\n";
    printStack(st3);
    cout << "Expected: Top -> 100 <- Bottom\n\n";


    cout << "===== Test Case 4 (Single Element Stack) =====\n";
    stack<int> st4;
    st4.push(7);

    cout << "Original Stack:\n";
    printStack(st4);

    int x4 = 42;
    cout << "Insert at Bottom: " << x4 << endl;

    sol.insertAtBottom(st4, x4);

    cout << "Modified Stack:\n";
    printStack(st4);
    cout << "Expected Bottom = 42\n\n";

    return 0;
}
