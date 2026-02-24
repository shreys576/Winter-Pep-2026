#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> bfsResult;
        vector<bool> visited(adj.size(), 0);
        queue<int> q;
        
        // start bfs from node 0
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            bfsResult.push_back(front);
            
            for(auto i : adj[front]){
                if(visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return bfsResult;
        
    }
};

// Helper to print vector
void printVector(vector<int> v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Graph:
    // 0 -- 1
    // |    |
    // 2 -- 3
    vector<vector<int>> adj1 = {
        {1,2},    // 0
        {0,3},    // 1
        {0,3},    // 2
        {1,2}     // 3
    };

    vector<int> ans1 = sol.bfs(adj1);
    cout << "BFS Traversal: ";
    printVector(ans1);
    cout << "Expected (one valid order): [ 0 1 2 3 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    // Graph:
    // 0 -> 1 -> 2 -> 3
    vector<vector<int>> adj2 = {
        {1},   // 0
        {2},   // 1
        {3},   // 2
        {}     // 3
    };

    vector<int> ans2 = sol.bfs(adj2);
    cout << "BFS Traversal: ";
    printVector(ans2);
    cout << "Expected: [ 0 1 2 3 ]\n\n";


    cout << "===== Test Case 3 (Disconnected Graph) =====\n";
    // Graph:
    // 0 -- 1    2 -- 3
    // BFS will only cover component containing 0
    vector<vector<int>> adj3 = {
        {1},    // 0
        {0},    // 1
        {3},    // 2
        {2}     // 3
    };

    vector<int> ans3 = sol.bfs(adj3);
    cout << "BFS Traversal: ";
    printVector(ans3);
    cout << "Expected: [ 0 1 ] (since BFS starts from 0)\n\n";


    cout << "===== Test Case 4 (Single Node) =====\n";
    vector<vector<int>> adj4 = {
        {}   // 0
    };

    vector<int> ans4 = sol.bfs(adj4);
    cout << "BFS Traversal: ";
    printVector(ans4);
    cout << "Expected: [ 0 ]\n\n";


    cout << "===== Test Case 5 =====\n";
    // Graph:
    // 0
    // | \
    // 1  2
    // |   \
    // 3    4
    vector<vector<int>> adj5 = {
        {1,2},   // 0
        {3},     // 1
        {4},     // 2
        {},      // 3
        {}       // 4
    };

    vector<int> ans5 = sol.bfs(adj5);
    cout << "BFS Traversal: ";
    printVector(ans5);
    cout << "Expected: [ 0 1 2 3 4 ]\n\n";

    return 0;
}