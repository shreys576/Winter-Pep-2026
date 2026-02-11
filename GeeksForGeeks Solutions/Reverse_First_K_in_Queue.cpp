#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> s1;
        stack<int> s2;
        if(k > q.size()) return q;
        for(int i = 0; i < k; i++){
            s1.push(q.front());
            q.pop();
        }
        while(!q.empty()){
            s2.push(q.front());
            q.pop();
        }
        while(!s1.empty()){
            q.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty()){
            q.push(s1.top());
            s1.pop();
        }
        return q;
    }
};

// Helper function to print queue
void printQueue(queue<int> q) {
    cout << "Front -> ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "<- Rear\n";
}

// Helper function to create queue from vector
queue<int> createQueue(vector<int> arr) {
    queue<int> q;
    for(int x : arr) q.push(x);
    return q;
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    queue<int> q1 = createQueue({1, 2, 3, 4, 5});
    int k1 = 3;

    cout << "Original Queue:\n";
    printQueue(q1);

    cout << "k = " << k1 << endl;

    queue<int> result1 = sol.reverseFirstK(q1, k1);

    cout << "Modified Queue:\n";
    printQueue(result1);
    cout << "Expected: 3 2 1 4 5\n\n";


    cout << "===== Test Case 2 =====\n";
    queue<int> q2 = createQueue({10, 20, 30, 40, 50});
    int k2 = 5;

    cout << "Original Queue:\n";
    printQueue(q2);

    cout << "k = " << k2 << endl;

    queue<int> result2 = sol.reverseFirstK(q2, k2);

    cout << "Modified Queue:\n";
    printQueue(result2);
    cout << "Expected: 50 40 30 20 10\n\n";


    cout << "===== Test Case 3 (k = 1) =====\n";
    queue<int> q3 = createQueue({1, 2, 3, 4});
    int k3 = 1;

    cout << "Original Queue:\n";
    printQueue(q3);

    cout << "k = " << k3 << endl;

    queue<int> result3 = sol.reverseFirstK(q3, k3);

    cout << "Modified Queue:\n";
    printQueue(result3);
    cout << "Expected: 1 2 3 4\n\n";


    cout << "===== Test Case 4 (k > size) =====\n";
    queue<int> q4 = createQueue({5, 6, 7});
    int k4 = 10;

    cout << "Original Queue:\n";
    printQueue(q4);

    cout << "k = " << k4 << endl;

    queue<int> result4 = sol.reverseFirstK(q4, k4);

    cout << "Modified Queue:\n";
    printQueue(result4);
    cout << "Expected: 5 6 7 (unchanged)\n\n";


    cout << "===== Test Case 5 (Empty Queue) =====\n";
    queue<int> q5 = createQueue({});
    int k5 = 2;

    cout << "Original Queue:\n";
    printQueue(q5);

    cout << "k = " << k5 << endl;

    queue<int> result5 = sol.reverseFirstK(q5, k5);

    cout << "Modified Queue:\n";
    printQueue(result5);
    cout << "Expected: (empty)\n\n";

    return 0;
}
