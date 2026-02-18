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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return root;
        if(root -> val == val) return root;

        if(root -> val < val){
            return searchBST(root -> right, val);
        }

        else{
            return searchBST(root -> left, val);
        }

        return NULL;
    }
};

// Helper function: inorder traversal print
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // BST:
    //        4
    //      /   \
    //     2     7
    //    / \
    //   1   3
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    int val1 = 2;
    TreeNode* ans1 = sol.searchBST(root1, val1);

    cout << "Searching for: " << val1 << endl;
    if(ans1 != NULL) {
        cout << "Found Node: " << ans1->val << endl;
        cout << "Subtree inorder: ";
        inorder(ans1);
        cout << endl;
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Expected: Found Node = 2, inorder = 1 2 3\n\n";


    cout << "===== Test Case 2 =====\n";
    int val2 = 7;
    TreeNode* ans2 = sol.searchBST(root1, val2);

    cout << "Searching for: " << val2 << endl;
    if(ans2 != NULL) {
        cout << "Found Node: " << ans2->val << endl;
        cout << "Subtree inorder: ";
        inorder(ans2);
        cout << endl;
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Expected: Found Node = 7, inorder = 7\n\n";


    cout << "===== Test Case 3 (Not Found) =====\n";
    int val3 = 5;
    TreeNode* ans3 = sol.searchBST(root1, val3);

    cout << "Searching for: " << val3 << endl;
    if(ans3 != NULL) {
        cout << "Found Node: " << ans3->val << endl;
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Expected: Not Found\n\n";


    cout << "===== Test Case 4 (Single Node BST) =====\n";
    TreeNode* root4 = new TreeNode(10);

    int val4 = 10;
    TreeNode* ans4 = sol.searchBST(root4, val4);

    cout << "Searching for: " << val4 << endl;
    if(ans4 != NULL) {
        cout << "Found Node: " << ans4->val << endl;
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Expected: Found Node = 10\n\n";


    cout << "===== Test Case 5 (Empty BST) =====\n";
    TreeNode* root5 = NULL;

    int val5 = 3;
    TreeNode* ans5 = sol.searchBST(root5, val5);

    cout << "Searching for: " << val5 << endl;
    if(ans5 != NULL) {
        cout << "Found Node: " << ans5->val << endl;
    }
    else {
        cout << "Not Found\n";
    }
    cout << "Expected: Not Found\n\n";

    return 0;
}
