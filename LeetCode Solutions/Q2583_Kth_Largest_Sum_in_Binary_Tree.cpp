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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        vector<long long> fin;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long levelSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                levelSum += frontNode -> val;
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            fin.push_back(levelSum);
        }
        sort(fin.begin(), fin.end());
        if(k > fin.size()) return -1;
        return fin[fin.size() - k];
    }
};

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Tree:
    //        5
    //       / \
    //      8   9
    //     / \   \
    //    2   1   3
    //
    // Level sums:
    // Level 0: 5
    // Level 1: 8 + 9 = 17
    // Level 2: 2 + 1 + 3 = 6
    // Sorted sums: [5, 6, 17]
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(8);
    root1->right = new TreeNode(9);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(3);

    int k1 = 2;
    cout << "k = " << k1 << endl;
    cout << "Output: " << sol.kthLargestLevelSum(root1, k1)
         << " (Expected: 6)\n\n";


    cout << "===== Test Case 2 =====\n";
    // Tree:
    //      1
    //     / \
    //    2   3
    //
    // Level sums: [1, 5]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    int k2 = 1;
    cout << "k = " << k2 << endl;
    cout << "Output: " << sol.kthLargestLevelSum(root2, k2)
         << " (Expected: 5)\n\n";


    cout << "===== Test Case 3 (k too large) =====\n";
    int k3 = 5;
    cout << "k = " << k3 << endl;
    cout << "Output: " << sol.kthLargestLevelSum(root2, k3)
         << " (Expected: -1)\n\n";


    cout << "===== Test Case 4 (Single Node Tree) =====\n";
    TreeNode* root4 = new TreeNode(10);

    int k4 = 1;
    cout << "k = " << k4 << endl;
    cout << "Output: " << sol.kthLargestLevelSum(root4, k4)
         << " (Expected: 10)\n\n";


    cout << "===== Test Case 5 (Negative Values) =====\n";
    // Tree:
    //       -1
    //      /  \
    //    -2   -3
    //   /
    // -4
    //
    // Level sums:
    // [-1, -5, -4]
    // Sorted: [-5, -4, -1]
    TreeNode* root5 = new TreeNode(-1);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(-3);
    root5->left->left = new TreeNode(-4);

    int k5 = 2;
    cout << "k = " << k5 << endl;
    cout << "Output: " << sol.kthLargestLevelSum(root5, k5)
         << " (Expected: -4)\n\n";

    return 0;
}
