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
        left = right = NULL;
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
        left = right = NULL;
    }
};

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == NULL) return -1;
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        return 1 + max(lh, rh);
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 (Empty Tree) =====\n";
    Node* root1 = NULL;
    cout << "Height: " << sol.height(root1) << " (Expected: -1)\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    Node* root2 = new Node(10);
    cout << "Height: " << sol.height(root2) << " (Expected: 0)\n\n";


    cout << "===== Test Case 3 =====\n";
    // Tree:
    //      1
    //     / \
    //    2   3
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);

    cout << "Height: " << sol.height(root3) << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 =====\n";
    // Tree:
    //        1
    //       /
    //      2
    //     /
    //    3
    //   /
    //  4
    Node* root4 = new Node(1);
    root4->left = new Node(2);
    root4->left->left = new Node(3);
    root4->left->left->left = new Node(4);

    cout << "Height: " << sol.height(root4) << " (Expected: 3)\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    Node* root5 = new Node(1);
    root5->left = new Node(2);
    root5->right = new Node(3);

    root5->left->left = new Node(4);
    root5->left->right = new Node(5);

    root5->right->right = new Node(6);

    cout << "Height: " << sol.height(root5) << " (Expected: 2)\n\n";

    return 0;
}
