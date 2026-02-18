#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int> result;
        if(root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        
        int count = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* frontNode = q.front();
                if(count == k){
                    result.push_back(frontNode -> data);
                }
                q.pop();
                
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            count++;
        }
        return result;
    }
};

// Helper function to print vector
void printVector(vector<int> v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    int k1 = 2;
    vector<int> ans1 = sol.Kdistance(root1, k1);
    cout << "Nodes at distance k = " << k1 << ": ";
    printVector(ans1);
    cout << "Expected: [ 4 5 6 7 ]\n\n";


    cout << "===== Test Case 2 =====\n";
    int k2 = 0;
    vector<int> ans2 = sol.Kdistance(root1, k2);
    cout << "Nodes at distance k = " << k2 << ": ";
    printVector(ans2);
    cout << "Expected: [ 1 ]\n\n";


    cout << "===== Test Case 3 =====\n";
    int k3 = 1;
    vector<int> ans3 = sol.Kdistance(root1, k3);
    cout << "Nodes at distance k = " << k3 << ": ";
    printVector(ans3);
    cout << "Expected: [ 2 3 ]\n\n";


    cout << "===== Test Case 4 (k too large) =====\n";
    int k4 = 5;
    vector<int> ans4 = sol.Kdistance(root1, k4);
    cout << "Nodes at distance k = " << k4 << ": ";
    printVector(ans4);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 5 (Single Node Tree) =====\n";
    Node* root5 = new Node(10);

    int k5 = 0;
    vector<int> ans5 = sol.Kdistance(root5, k5);
    cout << "Nodes at distance k = " << k5 << ": ";
    printVector(ans5);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 6 (Single Node Tree, k=1) =====\n";
    int k6 = 1;
    vector<int> ans6 = sol.Kdistance(root5, k6);
    cout << "Nodes at distance k = " << k6 << ": ";
    printVector(ans6);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 7 =====\n";
    // Tree:
    //        5
    //       / \
    //      8   9
    //     / \   \
    //    2   1   3
    Node* root7 = new Node(5);
    root7->left = new Node(8);
    root7->right = new Node(9);
    root7->left->left = new Node(2);
    root7->left->right = new Node(1);
    root7->right->right = new Node(3);

    int k7 = 2;
    vector<int> ans7 = sol.Kdistance(root7, k7);
    cout << "Nodes at distance k = " << k7 << ": ";
    printVector(ans7);
    cout << "Expected: [ 2 1 3 ]\n\n";

    return 0;
}
