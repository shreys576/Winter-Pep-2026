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

    void preorder(TreeNode* root, vector <int> &ans){
        if(root == NULL) return;
        ans.push_back(root -> val);
        preorder(root -> left, ans);
        preorder(root -> right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> fin;
        preorder(root, fin);
        return fin;
        
    }
};

// Helper function to print vector
void printVector(vector<int> v) {
    cout << "[ ";
    for(int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    vector<int> ans1 = sol.preorderTraversal(root1);
    cout << "Preorder Traversal: ";
    printVector(ans1);
    cout << "Expected: [ 1 2 3 ]\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);

    vector<int> ans2 = sol.preorderTraversal(root2);
    cout << "Preorder Traversal: ";
    printVector(ans2);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    TreeNode* root3 = NULL;

    vector<int> ans3 = sol.preorderTraversal(root3);
    cout << "Preorder Traversal: ";
    printVector(ans3);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 4 =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* root4 = new TreeNode(4);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(6);

    root4->left->left = new TreeNode(1);
    root4->left->right = new TreeNode(3);

    root4->right->left = new TreeNode(5);
    root4->right->right = new TreeNode(7);

    vector<int> ans4 = sol.preorderTraversal(root4);
    cout << "Preorder Traversal: ";
    printVector(ans4);
    cout << "Expected: [ 4 2 1 3 6 5 7 ]\n\n";

    return 0;
}
