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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(root == NULL) return 0;
        if(root -> val >= low && root -> val <= high){
            sum += root -> val;
        }
        return sum + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // BST:
    //        10
    //       /  \
    //      5    15
    //     / \     \
    //    3   7     18
    //
    // Range [7, 15] => 7 + 10 + 15 = 32
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);

    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(7);

    root1->right->right = new TreeNode(18);

    int low1 = 7, high1 = 15;
    cout << "Low = " << low1 << ", High = " << high1 << endl;
    cout << "Output: " << sol.rangeSumBST(root1, low1, high1)
         << " (Expected: 32)\n\n";


    cout << "===== Test Case 2 =====\n";
    // BST:
    //         10
    //        /  \
    //       5    15
    //      / \   / \
    //     3   7 13  18
    //    /       \
    //   1         14
    //
    // Range [6, 10] => 7 + 10 = 17
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);

    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(7);

    root2->left->left->left = new TreeNode(1);

    root2->right->left = new TreeNode(13);
    root2->right->right = new TreeNode(18);

    root2->right->left->right = new TreeNode(14);

    int low2 = 6, high2 = 10;
    cout << "Low = " << low2 << ", High = " << high2 << endl;
    cout << "Output: " << sol.rangeSumBST(root2, low2, high2)
         << " (Expected: 17)\n\n";


    cout << "===== Test Case 3 (Single Node in Range) =====\n";
    TreeNode* root3 = new TreeNode(8);

    int low3 = 5, high3 = 10;
    cout << "Low = " << low3 << ", High = " << high3 << endl;
    cout << "Output: " << sol.rangeSumBST(root3, low3, high3)
         << " (Expected: 8)\n\n";


    cout << "===== Test Case 4 (Single Node Out of Range) =====\n";
    TreeNode* root4 = new TreeNode(20);

    int low4 = 1, high4 = 10;
    cout << "Low = " << low4 << ", High = " << high4 << endl;
    cout << "Output: " << sol.rangeSumBST(root4, low4, high4)
         << " (Expected: 0)\n\n";


    cout << "===== Test Case 5 (Empty Tree) =====\n";
    TreeNode* root5 = NULL;

    int low5 = 5, high5 = 15;
    cout << "Low = " << low5 << ", High = " << high5 << endl;
    cout << "Output: " << sol.rangeSumBST(root5, low5, high5)
         << " (Expected: 0)\n\n";

    return 0;
}
