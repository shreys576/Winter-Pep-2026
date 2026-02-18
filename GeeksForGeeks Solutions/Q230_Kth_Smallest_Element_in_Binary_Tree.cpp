#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void Inorder(TreeNode* root, vector<int> &fin){
        if(root == NULL) return;
        Inorder(root -> left, fin);
        fin.push_back(root -> val);
        Inorder(root -> right, fin);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> fin;
        Inorder(root, fin);
        return fin[k - 1];
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // BST:
    //        3
    //       / \
    //      1   4
    //       \
    //        2
    //
    // Inorder: 1 2 3 4
    // k = 1 -> 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    int k1 = 1;
    cout << "k = " << k1 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root1, k1)
         << " (Expected: 1)\n\n";


    cout << "===== Test Case 2 =====\n";
    // k = 2 -> 2
    int k2 = 2;
    cout << "k = " << k2 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root1, k2)
         << " (Expected: 2)\n\n";


    cout << "===== Test Case 3 =====\n";
    // k = 4 -> 4
    int k3 = 4;
    cout << "k = " << k3 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root1, k3)
         << " (Expected: 4)\n\n";


    cout << "===== Test Case 4 =====\n";
    // BST:
    //        5
    //       / \
    //      3   6
    //     / \
    //    2   4
    //   /
    //  1
    //
    // Inorder: 1 2 3 4 5 6
    // k = 3 -> 3
    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(6);

    root4->left->left = new TreeNode(2);
    root4->left->right = new TreeNode(4);

    root4->left->left->left = new TreeNode(1);

    int k4 = 3;
    cout << "k = " << k4 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root4, k4)
         << " (Expected: 3)\n\n";


    cout << "===== Test Case 5 (Single Node Tree) =====\n";
    TreeNode* root5 = new TreeNode(10);

    int k5 = 1;
    cout << "k = " << k5 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root5, k5)
         << " (Expected: 10)\n\n";


    cout << "===== Test Case 6 (Negative Values BST) =====\n";
    // BST:
    //        0
    //       / \
    //     -3   9
    //     /   / \
    //   -5   5   12
    //
    // Inorder: -5 -3 0 5 9 12
    // k = 2 -> -3
    TreeNode* root6 = new TreeNode(0);
    root6->left = new TreeNode(-3);
    root6->right = new TreeNode(9);

    root6->left->left = new TreeNode(-5);
    root6->right->left = new TreeNode(5);
    root6->right->right = new TreeNode(12);

    int k6 = 2;
    cout << "k = " << k6 << endl;
    cout << "kth Smallest: " << sol.kthSmallest(root6, k6)
         << " (Expected: -3)\n\n";

    return 0;
}
