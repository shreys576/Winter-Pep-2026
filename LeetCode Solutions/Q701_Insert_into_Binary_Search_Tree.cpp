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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode = new TreeNode(val);
        if(root == NULL){
            root = newnode;
            return root;
        }
        if(root -> val > val) root -> left = insertIntoBST(root -> left, val);
        else root -> right = insertIntoBST(root -> right, val);
        return root;
    }
};

// Helper function: inorder traversal (BST inorder should be sorted)
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
    //      4
    //     / \
    //    2   7
    //   / \
    //  1   3
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);

    cout << "Inorder Before Insert: ";
    inorder(root1);
    cout << endl;

    int val1 = 5;
    root1 = sol.insertIntoBST(root1, val1);

    cout << "Inserted: " << val1 << endl;
    cout << "Inorder After Insert:  ";
    inorder(root1);
    cout << endl;
    cout << "Expected inorder: 1 2 3 4 5 7\n\n";


    cout << "===== Test Case 2 (Insert into Empty Tree) =====\n";
    TreeNode* root2 = NULL;
    int val2 = 10;

    root2 = sol.insertIntoBST(root2, val2);

    cout << "Inserted: " << val2 << endl;
    cout << "Inorder After Insert: ";
    inorder(root2);
    cout << endl;
    cout << "Expected inorder: 10\n\n";


    cout << "===== Test Case 3 =====\n";
    // Insert multiple values into empty tree
    TreeNode* root3 = NULL;
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x : values) {
        root3 = sol.insertIntoBST(root3, x);
    }

    cout << "Inserted values: ";
    for(int x : values) cout << x << " ";
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root3);
    cout << endl;
    cout << "Expected inorder: 1 3 4 6 7 8 10 13 14\n\n";


    cout << "===== Test Case 4 (Insert Duplicate) =====\n";
    // Your code inserts duplicates to the right
    int val4 = 6;
    root3 = sol.insertIntoBST(root3, val4);

    cout << "Inserted duplicate: " << val4 << endl;
    cout << "Inorder After Insert: ";
    inorder(root3);
    cout << endl;
    cout << "Expected inorder: 1 3 4 6 6 7 8 10 13 14\n\n";


    cout << "===== Test Case 5 (Insert Smaller Value) =====\n";
    int val5 = 0;
    root3 = sol.insertIntoBST(root3, val5);

    cout << "Inserted: " << val5 << endl;
    cout << "Inorder After Insert: ";
    inorder(root3);
    cout << endl;
    cout << "Expected inorder starts with 0\n\n";

    return 0;
}
