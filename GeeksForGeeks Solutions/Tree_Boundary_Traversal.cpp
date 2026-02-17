#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
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
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  
    void leftBoundary(Node* root, vector<int> &fin){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        
        fin.push_back(root -> data);
        if(root -> left != NULL) leftBoundary(root -> left, fin);
        else leftBoundary(root -> right, fin);
    }
    
    void rightBoundary(Node* root, vector<int> &fin){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        
        if(root -> right != NULL) rightBoundary(root -> right, fin);
        else rightBoundary(root -> left, fin);
        fin.push_back(root -> data);
        
    }
    
    void takeTrees(Node* root, vector<int> &fin){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            fin.push_back(root -> data);
            return;
        }
        takeTrees(root -> left, fin);
        takeTrees(root -> right, fin);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> fin;
        fin.push_back(root -> data);
        leftBoundary(root -> left, fin);
        takeTrees(root -> left, fin);
        takeTrees(root -> right, fin);
        rightBoundary(root -> right, fin);
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
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    //
    // Boundary traversal:
    // 1 2 4 5 6 7 3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    vector<int> ans1 = sol.boundaryTraversal(root1);
    cout << "Boundary Traversal: ";
    printVector(ans1);
    cout << "Expected: [ 1 2 4 5 6 7 3 ]\n\n";


    cout << "===== Test Case 2 (Left Skewed Tree) =====\n";
    // Tree:
    //   1
    //  /
    // 2
    /// 
    //3
    // Boundary: 1 2 3
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    vector<int> ans2 = sol.boundaryTraversal(root2);
    cout << "Boundary Traversal: ";
    printVector(ans2);
    cout << "Expected: [ 1 2 3 ]\n\n";


    cout << "===== Test Case 3 (Right Skewed Tree) =====\n";
    // Tree:
    // 1
    //  \
    //   2
    //    \
    //     3
    // Boundary: 1 3 2
    Node* root3 = new Node(1);
    root3->right = new Node(2);
    root3->right->right = new Node(3);

    vector<int> ans3 = sol.boundaryTraversal(root3);
    cout << "Boundary Traversal: ";
    printVector(ans3);
    cout << "Expected: [ 1 3 2 ]\n\n";


    cout << "===== Test Case 4 (Single Node Tree) =====\n";
    Node* root4 = new Node(10);

    vector<int> ans4 = sol.boundaryTraversal(root4);
    cout << "Boundary Traversal: ";
    printVector(ans4);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        20
    //       /  \
    //      8    22
    //     / \     \
    //    4  12     25
    //      /  \
    //     10  14
    //
    // Boundary: 20 8 4 10 14 25 22
    Node* root5 = new Node(20);
    root5->left = new Node(8);
    root5->right = new Node(22);

    root5->left->left = new Node(4);
    root5->left->right = new Node(12);

    root5->left->right->left = new Node(10);
    root5->left->right->right = new Node(14);

    root5->right->right = new Node(25);

    vector<int> ans5 = sol.boundaryTraversal(root5);
    cout << "Boundary Traversal: ";
    printVector(ans5);
    cout << "Expected: [ 20 8 4 10 14 25 22 ]\n\n";

    return 0;
}
