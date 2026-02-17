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
    vector<int> leftView(Node *root) {
        // code here
        vector<int> fin;
        if(root == NULL) return fin;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> levelElements;
            for(int i = 0; i < size; i++){
                Node* frontNode = q.front();
                q.pop();
                levelElements.push_back(frontNode -> data);
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            fin.push_back(levelElements[0]);
        }
        return fin;
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
    //       / \
    //      2   3
    //       \   \
    //        4   5
    //
    // Left view: [1,2,4]
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(4);
    root1->right->right = new Node(5);

    vector<int> ans1 = sol.leftView(root1);
    cout << "Left View: ";
    printVector(ans1);
    cout << "Expected: [ 1 2 4 ]\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    Node* root2 = new Node(10);

    vector<int> ans2 = sol.leftView(root2);
    cout << "Left View: ";
    printVector(ans2);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    Node* root3 = NULL;

    vector<int> ans3 = sol.leftView(root3);
    cout << "Left View: ";
    printVector(ans3);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 4 (Left Skewed Tree) =====\n";
    // Tree:
    //    1
    //   /
    //  2
    // /
    //3
    //
    // Left view: [1,2,3]
    Node* root4 = new Node(1);
    root4->left = new Node(2);
    root4->left->left = new Node(3);

    vector<int> ans4 = sol.leftView(root4);
    cout << "Left View: ";
    printVector(ans4);
    cout << "Expected: [ 1 2 3 ]\n\n";


    cout << "===== Test Case 5 (Perfect Tree) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    //
    // Left view: [4,2,1]
    Node* root5 = new Node(4);
    root5->left = new Node(2);
    root5->right = new Node(6);

    root5->left->left = new Node(1);
    root5->left->right = new Node(3);

    root5->right->left = new Node(5);
    root5->right->right = new Node(7);

    vector<int> ans5 = sol.leftView(root5);
    cout << "Left View: ";
    printVector(ans5);
    cout << "Expected: [ 4 2 1 ]\n\n";

    return 0;
}
