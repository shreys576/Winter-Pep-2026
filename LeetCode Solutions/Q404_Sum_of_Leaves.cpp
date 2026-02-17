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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        if(root -> left != NULL && root -> left -> left == NULL && root -> left -> right == NULL){
            sum += root -> left -> val;
        }
        return sum + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
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

    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root1)
         << " (Expected: 24)\n\n"; // 9 + 15


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(1);

    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root2)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 3 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);

    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root3)
         << " (Expected: 4)\n\n";


    cout << "===== Test Case 4 =====\n";
    // Tree:
    //        10
    //       /  \
    //      5    15
    //       \
    //        7
    TreeNode* root4 = new TreeNode(10);
    root4->left = new TreeNode(5);
    root4->right = new TreeNode(15);
    root4->left->right = new TreeNode(7);

    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root4)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 =====\n";
    // Tree:
    //        1
    //       /
    //      2
    //     /
    //    3
    //   /
    //  4
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->left->left = new TreeNode(3);
    root5->left->left->left = new TreeNode(4);

    cout << "Sum of Left Leaves: " << sol.sumOfLeftLeaves(root5)
         << " (Expected: 4)\n\n";

    return 0;
}
