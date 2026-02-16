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

    void countemall(TreeNode* root, int &count){
        if(root == NULL) return;
        count++;
        countemall(root -> left, count);
        countemall(root -> right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        countemall(root, count);
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
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    cout << "Node Count: " << sol.countNodes(root1) << " (Expected: 3)\n\n";


    cout << "===== Test Case 2 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    cout << "Node Count: " << sol.countNodes(root2) << " (Expected: 5)\n\n";


    cout << "===== Test Case 3 (Single Node) =====\n";
    TreeNode* root3 = new TreeNode(10);

    cout << "Node Count: " << sol.countNodes(root3) << " (Expected: 1)\n\n";


    cout << "===== Test Case 4 (Empty Tree) =====\n";
    TreeNode* root4 = NULL;

    cout << "Node Count: " << sol.countNodes(root4) << " (Expected: 0)\n\n";


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

    cout << "Node Count: " << sol.countNodes(root5) << " (Expected: 7)\n\n";

    return 0;
}
