#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
};

// Helper function to print queue (without modifying original)
void printQueue(queue<int> q) {
    cout << "Front -> ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "<- Rear\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout << "Original Queue:\n";
    printQueue(q1);

    sol.reverseQueue(q1);

    cout << "Reversed Queue:\n";
    printQueue(q1);
    cout << "Expected: 5 4 3 2 1\n\n";


    cout << "===== Test Case 2 (Single Element) =====\n";
    queue<int> q2;
    q2.push(10);

    cout << "Original Queue:\n";
    printQueue(q2);

    sol.reverseQueue(q2);

    cout << "Reversed Queue:\n";
    printQueue(q2);
    cout << "Expected: 10\n\n";


    cout << "===== Test Case 3 (Empty Queue) =====\n";
    queue<int> q3;

    cout << "Original Queue:\n";
    printQueue(q3);

    sol.reverseQueue(q3);

    cout << "Reversed Queue:\n";
    printQueue(q3);
    cout << "Expected: (empty)\n\n";


    cout << "===== Test Case 4 =====\n";
    queue<int> q4;
    q4.push(100);
    q4.push(200);
    q4.push(300);

    cout << "Original Queue:\n";
    printQueue(q4);

    sol.reverseQueue(q4);

    cout << "Reversed Queue:\n";
    printQueue(q4);
    cout << "Expected: 300 200 100\n\n";

    return 0;
}
