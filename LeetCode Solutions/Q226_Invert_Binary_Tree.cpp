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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        swap(root -> left, root -> right);

        invertTree(root -> left);
        invertTree(root -> right);

        return root;
    }
};

// Helper function: inorder traversal print
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function: level order print
void levelOrder(TreeNode* root) {
    if(root == NULL) {
        cout << "(empty)\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            TreeNode* node = q.front();
            q.pop();

            if(node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     7
    //    / \   / \
    //   1   3 6   9
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);

    cout << "Inorder Before Invert: ";
    inorder(root1);
    cout << endl;

    sol.invertTree(root1);

    cout << "Inorder After Invert:  ";
    inorder(root1);
    cout << endl;

    cout << "Expected inorder after invert: 9 7 6 4 3 2 1\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);

    cout << "Inorder Before Invert: ";
    inorder(root2);
    cout << endl;

    sol.invertTree(root2);

    cout << "Inorder After Invert:  ";
    inorder(root2);
    cout << endl;

    cout << "Expected: 10\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    TreeNode* root3 = NULL;

    TreeNode* inv3 = sol.invertTree(root3);

    if(inv3 == NULL) cout << "Output: NULL (Expected: NULL)\n\n";


    cout << "===== Test Case 4 (Left Skewed Tree) =====\n";
    // Tree:
    //    1
    //   /
    //  2
    // /
    //3
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);

    cout << "Inorder Before Invert: ";
    inorder(root4);
    cout << endl;

    sol.invertTree(root4);

    cout << "Inorder After Invert:  ";
    inorder(root4);
    cout << endl;

    cout << "Expected inorder after invert: 1 2 3\n\n";


    cout << "===== Test Case 5 (Level Order View) =====\n";
    // Tree:
    //      2
    //     / \
    //    1   3
    TreeNode* root5 = new TreeNode(2);
    root5->left = new TreeNode(1);
    root5->right = new TreeNode(3);

    cout << "Level Order Before Invert:\n";
    levelOrder(root5);

    sol.invertTree(root5);

    cout << "Level Order After Invert:\n";
    levelOrder(root5);

    cout << "Expected after invert:\n";
    cout << "2\n3 1\n\n";

    return 0;
}
