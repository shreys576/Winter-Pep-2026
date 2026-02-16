#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Class Solution
class Solution {
  public:
    
    void countleaf(Node* root, int &count){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            count++;
        }
        countleaf(root -> left, count);
        countleaf(root -> right, count);
    }
    
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int count = 0;
        countleaf(root, count);
        return count;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //      1
    //     / \
    //    2   3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    cout << "Leaf Count: " << sol.countLeaves(root1) << " (Expected: 2)\n\n";


    cout << "===== Test Case 2 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    cout << "Leaf Count: " << sol.countLeaves(root2) << " (Expected: 3)\n\n";


    cout << "===== Test Case 3 (Single Node Tree) =====\n";
    Node* root3 = new Node(10);

    cout << "Leaf Count: " << sol.countLeaves(root3) << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 (Empty Tree) =====\n";
    Node* root4 = NULL;

    cout << "Leaf Count: " << sol.countLeaves(root4) << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    Node* root5 = new Node(4);
    root5->left = new Node(2);
    root5->right = new Node(6);

    root5->left->left = new Node(1);
    root5->left->right = new Node(3);

    root5->right->left = new Node(5);
    root5->right->right = new Node(7);

    cout << "Leaf Count: " << sol.countLeaves(root5) << " (Expected: 4)\n\n";

    return 0;
}
