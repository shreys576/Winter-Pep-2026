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

    int height(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + max(height(root -> left), height(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = height(root -> left);
        int rh = height(root -> right);
        if(abs(lh - rh) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 (Balanced Tree) =====\n";
    // Tree:
    //        3
    //       / \
    //      9   20
    //         /  \
    //        15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Output: " << sol.isBalanced(root1) << " (Expected: 1)\n\n";


    cout << "===== Test Case 2 (Unbalanced Tree) =====\n";
    // Tree:
    //        1
    //       /
    //      2
    //     /
    //    3
    //   /
    //  4
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);

    cout << "Output: " << sol.isBalanced(root2) << " (Expected: 0)\n\n";


    cout << "===== Test Case 3 (Single Node) =====\n";
    TreeNode* root3 = new TreeNode(10);

    cout << "Output: " << sol.isBalanced(root3) << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 (Empty Tree) =====\n";
    TreeNode* root4 = NULL;

    cout << "Output: " << sol.isBalanced(root4) << " (Expected: 1)\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(2);

    root5->left->left = new TreeNode(3);
    root5->left->right = new TreeNode(3);

    root5->left->left->left = new TreeNode(4);
    root5->left->left->right = new TreeNode(4);

    cout << "Output: " << sol.isBalanced(root5) << " (Expected: 0)\n\n";


    cout << "===== Test Case 6 (Perfect Balanced Tree) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* root6 = new TreeNode(4);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(6);

    root6->left->left = new TreeNode(1);
    root6->left->right = new TreeNode(3);

    root6->right->left = new TreeNode(5);
    root6->right->right = new TreeNode(7);

    cout << "Output: " << sol.isBalanced(root6) << " (Expected: 1)\n\n";

    return 0;
}
