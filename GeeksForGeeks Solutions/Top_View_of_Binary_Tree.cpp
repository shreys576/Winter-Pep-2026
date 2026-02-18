#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> result;
        
        if(root == NULL) return result;
        
        //we will create a map to store first node at each horizontal distance
        //key -> horizontal distance - hd
        //value -> node value
        
        map<int,int> topNode;
        
        //create a queue to store pair of node and hd
        queue<pair<Node* , int>> q;
        
        //start with root at hd -> 0
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            //extract the front pair
            pair<Node*, int> frontVal = q.front();
            q.pop();
            
            Node* node = frontVal.first;
            int hd = frontVal.second;
            
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = node-> data;
            }
            
            if(node -> left != NULL){
                q.push(make_pair(node -> left, hd - 1));
            }
            if(node -> right != NULL){
                q.push(make_pair(node -> right, hd + 1));
            }
        }
        
        for(auto i : topNode){
            result.push_back(i.second);
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
    //      \
    //       4
    //        \
    //         5
    //          \
    //           6
    //
    // Top View: 2 1 3 6
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(4);
    root1->left->right->right = new Node(5);
    root1->left->right->right->right = new Node(6);

    vector<int> ans1 = sol.topView(root1);
    cout << "Top View: ";
    printVector(ans1);
    cout << "Expected: [ 2 1 3 6 ]\n\n";


    cout << "===== Test Case 2 (Perfect Tree) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    //
    // Top View: 1 2 4 6 7
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    root2->left->left = new Node(1);
    root2->left->right = new Node(3);

    root2->right->left = new Node(5);
    root2->right->right = new Node(7);

    vector<int> ans2 = sol.topView(root2);
    cout << "Top View: ";
    printVector(ans2);
    cout << "Expected: [ 1 2 4 6 7 ]\n\n";


    cout << "===== Test Case 3 (Single Node) =====\n";
    Node* root3 = new Node(10);

    vector<int> ans3 = sol.topView(root3);
    cout << "Top View: ";
    printVector(ans3);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 4 (Empty Tree) =====\n";
    Node* root4 = NULL;

    vector<int> ans4 = sol.topView(root4);
    cout << "Top View: ";
    printVector(ans4);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     /     \
    //    4       5
    //
    // Top View: 4 2 1 3 5
    Node* root5 = new Node(1);
    root5->left = new Node(2);
    root5->right = new Node(3);

    root5->left->left = new Node(4);
    root5->right->right = new Node(5);

    vector<int> ans5 = sol.topView(root5);
    cout << "Top View: ";
    printVector(ans5);
    cout << "Expected: [ 4 2 1 3 5 ]\n\n";

    return 0;
}
