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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ld = maxDepth(root -> left);
        int rd = maxDepth(root -> right);

        return 1 + max(ld,rd);
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 (Empty Tree) =====\n";
    TreeNode* root1 = NULL;
    cout << "Max Depth: " << sol.maxDepth(root1) << " (Expected: 0)\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);
    cout << "Max Depth: " << sol.maxDepth(root2) << " (Expected: 1)\n\n";


    cout << "===== Test Case 3 =====\n";
    // Tree:
    //      1
    //     / \
    //    2   3
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);

    cout << "Max Depth: " << sol.maxDepth(root3) << " (Expected: 2)\n\n";


    cout << "===== Test Case 4 (Skewed Tree) =====\n";
    // Tree:
    //      1
    //     /
    //    2
    //   /
    //  3
    // /
    //4
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    root4->left->left->left = new TreeNode(4);

    cout << "Max Depth: " << sol.maxDepth(root4) << " (Expected: 4)\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* root5 = new TreeNode(4);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(6);

    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(3);

    root5->right->left = new TreeNode(5);
    root5->right->right = new TreeNode(7);

    cout << "Max Depth: " << sol.maxDepth(root5) << " (Expected: 3)\n\n";

    return 0;
}
