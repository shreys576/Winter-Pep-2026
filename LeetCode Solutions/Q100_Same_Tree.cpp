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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if((p == NULL && q != NULL) || (p !=  NULL && q == NULL)) return false; 
        if(p -> val == q -> val){
            return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
        }
        else return false;
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 (Same Trees) =====\n";
    // Tree 1:
    //     1
    //    / \
    //   2   3
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    // Tree 2:
    //     1
    //    / \
    //   2   3
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "Output: " << sol.isSameTree(p1, q1) << " (Expected: 1)\n\n";


    cout << "===== Test Case 2 (Different Structure) =====\n";
    // Tree 1:
    //     1
    //    /
    //   2
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    // Tree 2:
    //     1
    //      \
    //       2
    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "Output: " << sol.isSameTree(p2, q2) << " (Expected: 0)\n\n";


    cout << "===== Test Case 3 (Different Values) =====\n";
    // Tree 1:
    //     1
    //    / \
    //   2   1
    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);
    p3->right = new TreeNode(1);

    // Tree 2:
    //     1
    //    / \
    //   1   2
    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(1);
    q3->right = new TreeNode(2);

    cout << "Output: " << sol.isSameTree(p3, q3) << " (Expected: 0)\n\n";


    cout << "===== Test Case 4 (Both Empty) =====\n";
    TreeNode* p4 = NULL;
    TreeNode* q4 = NULL;

    cout << "Output: " << sol.isSameTree(p4, q4) << " (Expected: 1)\n\n";


    cout << "===== Test Case 5 (One Empty) =====\n";
    TreeNode* p5 = new TreeNode(5);
    TreeNode* q5 = NULL;

    cout << "Output: " << sol.isSameTree(p5, q5) << " (Expected: 0)\n\n";


    cout << "===== Test Case 6 (Same Bigger Trees) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* p6 = new TreeNode(4);
    p6->left = new TreeNode(2);
    p6->right = new TreeNode(6);
    p6->left->left = new TreeNode(1);
    p6->left->right = new TreeNode(3);
    p6->right->left = new TreeNode(5);
    p6->right->right = new TreeNode(7);

    TreeNode* q6 = new TreeNode(4);
    q6->left = new TreeNode(2);
    q6->right = new TreeNode(6);
    q6->left->left = new TreeNode(1);
    q6->left->right = new TreeNode(3);
    q6->right->left = new TreeNode(5);
    q6->right->right = new TreeNode(7);

    cout << "Output: " << sol.isSameTree(p6, q6) << " (Expected: 1)\n\n";

    return 0;
}
