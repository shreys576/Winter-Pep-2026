#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1;
        queue<int> q2;
        
        int n = q.size();
        n = n / 2;
        for(int i = 0; i < n; i ++){
            q1.push(q.front());
            q.pop();
        }
        while(!q.empty()){
            q2.push(q.front());
            q.pop();
        }
        while(!q1.empty() && !q2.empty()){
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }
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
    queue<int> q1 = createQueue({1, 2, 3, 4});
    cout << "Original Queue:\n";
    printQueue(q1);

    sol.rearrangeQueue(q1);

    cout << "Rearranged Queue:\n";
    printQueue(q1);
    cout << "Expected: 1 3 2 4\n\n";


    cout << "===== Test Case 2 =====\n";
    queue<int> q2 = createQueue({10, 20, 30, 40, 50, 60});
    cout << "Original Queue:\n";
    printQueue(q2);

    sol.rearrangeQueue(q2);

    cout << "Rearranged Queue:\n";
    printQueue(q2);
    cout << "Expected: 10 40 20 50 30 60\n\n";


    cout << "===== Test Case 3 =====\n";
    queue<int> q3 = createQueue({1, 2});
    cout << "Original Queue:\n";
    printQueue(q3);

    sol.rearrangeQueue(q3);

    cout << "Rearranged Queue:\n";
    printQueue(q3);
    cout << "Expected: 1 2\n\n";


    cout << "===== Test Case 4 (Odd size queue) =====\n";
    queue<int> q4 = createQueue({1, 2, 3, 4, 5});
    cout << "Original Queue:\n";
    printQueue(q4);

    sol.rearrangeQueue(q4);

    cout << "Rearranged Queue:\n";
    printQueue(q4);
    cout << "Expected: 1 3 2 4 (and 5 is ignored in your logic)\n\n";


    cout << "===== Test Case 5 (Empty queue) =====\n";
    queue<int> q5 = createQueue({});
    cout << "Original Queue:\n";
    printQueue(q5);

    sol.rearrangeQueue(q5);

    cout << "Rearranged Queue:\n";
    printQueue(q5);
    cout << "Expected: (empty)\n\n";

    return 0;
}
