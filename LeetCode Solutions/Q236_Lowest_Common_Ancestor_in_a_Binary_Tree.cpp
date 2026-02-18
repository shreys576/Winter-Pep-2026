#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q){
            return root;
        }
        TreeNode* leftLCA = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root -> right, p, q);

        if(leftLCA != NULL && rightLCA != NULL){
            return root;
        }
        else if(leftLCA != NULL) return leftLCA;
        else return rightLCA;
    }
};

// Helper function to find node pointer by value
TreeNode* findNode(TreeNode* root, int val) {
    if(root == NULL) return NULL;
    if(root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if(left != NULL) return left;

    return findNode(root->right, val);
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //          3
    //        /   \
    //       5     1
    //      / \   / \
    //     6   2 0   8
    //        / \
    //       7   4
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);

    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);

    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);

    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);

    TreeNode* ans1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "LCA of 5 and 1: " << ans1->val << " (Expected: 3)\n\n";


    cout << "===== Test Case 2 =====\n";
    TreeNode* p2 = findNode(root1, 5);
    TreeNode* q2 = findNode(root1, 4);

    TreeNode* ans2 = sol.lowestCommonAncestor(root1, p2, q2);
    cout << "LCA of 5 and 4: " << ans2->val << " (Expected: 5)\n\n";


    cout << "===== Test Case 3 =====\n";
    TreeNode* p3 = findNode(root1, 6);
    TreeNode* q3 = findNode(root1, 4);

    TreeNode* ans3 = sol.lowestCommonAncestor(root1, p3, q3);
    cout << "LCA of 6 and 4: " << ans3->val << " (Expected: 5)\n\n";


    cout << "===== Test Case 4 (Same Node) =====\n";
    TreeNode* p4 = findNode(root1, 7);
    TreeNode* q4 = findNode(root1, 7);

    TreeNode* ans4 = sol.lowestCommonAncestor(root1, p4, q4);
    cout << "LCA of 7 and 7: " << ans4->val << " (Expected: 7)\n\n";


    cout << "===== Test Case 5 (Single Node Tree) =====\n";
    TreeNode* root5 = new TreeNode(10);

    TreeNode* p5 = root5;
    TreeNode* q5 = root5;

    TreeNode* ans5 = sol.lowestCommonAncestor(root5, p5, q5);
    cout << "LCA of 10 and 10: " << ans5->val << " (Expected: 10)\n\n";


    cout << "===== Test Case 6 (Empty Tree) =====\n";
    TreeNode* root6 = NULL;
    TreeNode* p6 = NULL;
    TreeNode* q6 = NULL;

    TreeNode* ans6 = sol.lowestCommonAncestor(root6, p6, q6);
    if(ans6 == NULL)
        cout << "LCA Output: NULL (Expected: NULL)\n\n";

    return 0;
}
