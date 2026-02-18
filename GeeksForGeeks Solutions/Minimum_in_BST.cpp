#include <bits/stdc++.h>
using namespace std;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
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

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int minValue(Node* root) {
        // code here
        Node* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp -> data;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // BST:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);

    cout << "Min Value: " << sol.minValue(root1) << " (Expected: 1)\n\n";


    cout << "===== Test Case 2 (Single Node BST) =====\n";
    Node* root2 = new Node(10);

    cout << "Min Value: " << sol.minValue(root2) << " (Expected: 10)\n\n";


    cout << "===== Test Case 3 (Left Skewed BST) =====\n";
    // BST:
    //     5
    //    /
    //   4
    //  /
    // 3
    // ...
    Node* root3 = new Node(5);
    root3->left = new Node(4);
    root3->left->left = new Node(3);
    root3->left->left->left = new Node(2);
    root3->left->left->left->left = new Node(1);

    cout << "Min Value: " << sol.minValue(root3) << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 =====\n";
    // BST:
    //        20
    //       /  \
    //      10   30
    //     / \
    //    5  15
    Node* root4 = new Node(20);
    root4->left = new Node(10);
    root4->right = new Node(30);
    root4->left->left = new Node(5);
    root4->left->right = new Node(15);

    cout << "Min Value: " << sol.minValue(root4) << " (Expected: 5)\n\n";

    return 0;
}
