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

    bool findTarget(TreeNode* root, int k) {
        vector<int> fin;
        Inorder(root, fin);
        int l = 0;
        int r = fin.size() - 1;
        while(l < r){
            int sum = fin[l] + fin[r];
            if(sum == k) return true;
            else if(sum > k) r--;
            else l++;
        }
        return false;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // BST:
    //        5
    //       / \
    //      3   6
    //     / \   \
    //    2   4   7
    //
    // k = 9 => true (2 + 7)
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(7);

    int k1 = 9;
    cout << "k = " << k1 << endl;
    cout << "Output: " << (sol.findTarget(root1, k1) ? "true" : "false") 
         << " (Expected: true)\n\n";


    cout << "===== Test Case 2 =====\n";
    // k = 28 => false
    int k2 = 28;
    cout << "k = " << k2 << endl;
    cout << "Output: " << (sol.findTarget(root1, k2) ? "true" : "false") 
         << " (Expected: false)\n\n";


    cout << "===== Test Case 3 =====\n";
    // k = 6 => true (2 + 4)
    int k3 = 6;
    cout << "k = " << k3 << endl;
    cout << "Output: " << (sol.findTarget(root1, k3) ? "true" : "false") 
         << " (Expected: true)\n\n";


    cout << "===== Test Case 4 (Single Node Tree) =====\n";
    TreeNode* root4 = new TreeNode(10);

    int k4 = 20;
    cout << "k = " << k4 << endl;
    cout << "Output: " << (sol.findTarget(root4, k4) ? "true" : "false") 
         << " (Expected: false)\n\n";


    cout << "===== Test Case 5 (Empty Tree) =====\n";
    TreeNode* root5 = NULL;

    int k5 = 10;
    cout << "k = " << k5 << endl;
    cout << "Output: " << (sol.findTarget(root5, k5) ? "true" : "false") 
         << " (Expected: false)\n\n";


    cout << "===== Test Case 6 (Negative Values BST) =====\n";
    // BST:
    //       0
    //      / \
    //    -3   5
    //    /   / \
    //  -4   2   7
    //
    // k = -7 => true (-4 + -3)
    TreeNode* root6 = new TreeNode(0);
    root6->left = new TreeNode(-3);
    root6->right = new TreeNode(5);
    root6->left->left = new TreeNode(-4);
    root6->right->left = new TreeNode(2);
    root6->right->right = new TreeNode(7);

    int k6 = -7;
    cout << "k = " << k6 << endl;
    cout << "Output: " << (sol.findTarget(root6, k6) ? "true" : "false") 
         << " (Expected: true)\n\n";

    return 0;
}
