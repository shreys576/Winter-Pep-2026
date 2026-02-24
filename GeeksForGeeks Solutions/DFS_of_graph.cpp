#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void helper(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result){
        visited[node] = 1;
        result.push_back(node);
        
        for(auto i : adj[node]){
            if(visited[i] == 0){
                helper(i, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size(), 0);
        vector<int> result;
        
        helper(0, adj, visited, result);
        return result;
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

    vector<int> ans1 = sol.dfs(adj1);
    cout << "DFS Traversal: ";
    printVector(ans1);
    cout << "Expected (one valid order): [ 0 1 3 2 ] or similar\n\n";


    cout << "===== Test Case 2 =====\n";
    // Linear graph: 0 -> 1 -> 2 -> 3
    vector<vector<int>> adj2 = {
        {1},   // 0
        {2},   // 1
        {3},   // 2
        {}     // 3
    };

    vector<int> ans2 = sol.dfs(adj2);
    cout << "DFS Traversal: ";
    printVector(ans2);
    cout << "Expected: [ 0 1 2 3 ]\n\n";


    cout << "===== Test Case 3 (Disconnected Graph) =====\n";
    // 0 -- 1    2 -- 3
    // DFS starts only from 0
    vector<vector<int>> adj3 = {
        {1},    // 0
        {0},    // 1
        {3},    // 2
        {2}     // 3
    };

    vector<int> ans3 = sol.dfs(adj3);
    cout << "DFS Traversal: ";
    printVector(ans3);
    cout << "Expected: [ 0 1 ] (since DFS starts from 0)\n\n";


    cout << "===== Test Case 4 (Single Node) =====\n";
    vector<vector<int>> adj4 = {
        {}   // 0
    };

    vector<int> ans4 = sol.dfs(adj4);
    cout << "DFS Traversal: ";
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

    vector<int> ans5 = sol.dfs(adj5);
    cout << "DFS Traversal: ";
    printVector(ans5);
    cout << "Expected (one valid order): [ 0 1 3 2 4 ]\n\n";

    return 0;
}