#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int index;
        if(s.size() % 2 != 0){
            index = s.size() / 2;
        }
        else{
            index = (s.size()/2);
        }
        stack<int> dummy;
        for(int i = 0; i < index; i++){
            int temp = s.top();
            s.pop();
            dummy.push(temp);
        }
        s.pop();
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            dummy.push(temp);
        }
        while(!dummy.empty()){
            int temp = dummy.top();
            dummy.pop();
            s.push(temp);
        }
    }
};

// Helper function to print stack (without modifying original)
void printStack(stack<int> s) {
    cout << "Top -> ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "<- Bottom\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 (Odd size stack) =====\n";
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout << "Original Stack:\n";
    printStack(s1);

    sol.deleteMid(s1);

    cout << "After deleteMid:\n";
    printStack(s1);
    cout << "Expected: middle element (3) removed\n\n";


    cout << "===== Test Case 2 (Even size stack) =====\n";
    stack<int> s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);

    cout << "Original Stack:\n";
    printStack(s2);

    sol.deleteMid(s2);

    cout << "After deleteMid:\n";
    printStack(s2);
    cout << "Expected: element removed depends on your index logic\n\n";


    cout << "===== Test Case 3 (Single element stack) =====\n";
    stack<int> s3;
    s3.push(99);

    cout << "Original Stack:\n";
    printStack(s3);

    sol.deleteMid(s3);

    cout << "After deleteMid:\n";
    printStack(s3);
    cout << "Expected: empty stack\n\n";


    cout << "===== Test Case 4 (Two elements stack) =====\n";
    stack<int> s4;
    s4.push(5);
    s4.push(15);

    cout << "Original Stack:\n";
    printStack(s4);

    sol.deleteMid(s4);

    cout << "After deleteMid:\n";
    printStack(s4);
    cout << "Expected: one element left\n\n";

    return 0;
}
