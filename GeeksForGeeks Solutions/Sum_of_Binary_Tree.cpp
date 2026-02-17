#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root == NULL) return 0;
        return root -> data + sumBT(root -> left) + sumBT(root -> right);
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

    cout << "Sum of Tree: " << sol.sumBT(root1) << " (Expected: 6)\n\n";


    cout << "===== Test Case 2 =====\n";
    // Tree:
    //        10
    //       /  \
    //      5    20
    //     / \     \
    //    3   7     30
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);

    root2->left->left = new Node(3);
    root2->left->right = new Node(7);

    root2->right->right = new Node(30);

    cout << "Sum of Tree: " << sol.sumBT(root2) << " (Expected: 75)\n\n";


    cout << "===== Test Case 3 (Single Node) =====\n";
    Node* root3 = new Node(100);

    cout << "Sum of Tree: " << sol.sumBT(root3) << " (Expected: 100)\n\n";


    cout << "===== Test Case 4 (Empty Tree) =====\n";
    Node* root4 = NULL;

    cout << "Sum of Tree: " << sol.sumBT(root4) << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 (Negative Values) =====\n";
    // Tree:
    //      -1
    //     /  \
    //   -2   -3
    //   /
    // -4
    Node* root5 = new Node(-1);
    root5->left = new Node(-2);
    root5->right = new Node(-3);
    root5->left->left = new Node(-4);

    cout << "Sum of Tree: " << sol.sumBT(root5) << " (Expected: -10)\n\n";

    return 0;
}
