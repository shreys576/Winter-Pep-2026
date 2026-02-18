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

    TreeNode* makeBST(TreeNode* root, vector<int> &nums, int l, int r){
        if(l > r) return NULL;
        int mid = (l + r)/2;
        TreeNode* newnode = new TreeNode(nums[mid]);
        root = newnode;
        root -> left = makeBST(root -> left, nums, l, mid - 1);
        root -> right = makeBST(root -> right, nums, mid + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //find mid element -> (l + r) / 2
        //make nums[mid] the curr node
        // recursively build -
        //LST -> nums[l]....... mid - 1
        //RST -> nums[mid + 1].......r
        //return
        int l = 0;
        int r = nums.size() - 1;
        TreeNode* root = new TreeNode(0);
        root = makeBST(root, nums, l, r);
        return root;

    }
};

// Helper function: inorder traversal (should print sorted array if BST correct)
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function: level order traversal print
void levelOrder(TreeNode* root) {
    if(root == NULL) {
        cout << "(empty)\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
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
    vector<int> nums1 = {-10, -3, 0, 5, 9};

    TreeNode* root1 = sol.sortedArrayToBST(nums1);

    cout << "Inorder Traversal: ";
    inorder(root1);
    cout << "\nExpected: -10 -3 0 5 9\n";

    cout << "Level Order Traversal:\n";
    levelOrder(root1);
    cout << endl;


    cout << "===== Test Case 2 =====\n";
    vector<int> nums2 = {1, 3};

    TreeNode* root2 = sol.sortedArrayToBST(nums2);

    cout << "Inorder Traversal: ";
    inorder(root2);
    cout << "\nExpected: 1 3\n";

    cout << "Level Order Traversal:\n";
    levelOrder(root2);
    cout << endl;


    cout << "===== Test Case 3 (Single Element) =====\n";
    vector<int> nums3 = {7};

    TreeNode* root3 = sol.sortedArrayToBST(nums3);

    cout << "Inorder Traversal: ";
    inorder(root3);
    cout << "\nExpected: 7\n";

    cout << "Level Order Traversal:\n";
    levelOrder(root3);
    cout << endl;


    cout << "===== Test Case 4 (Larger Array) =====\n";
    vector<int> nums4 = {1,2,3,4,5,6,7,8,9};

    TreeNode* root4 = sol.sortedArrayToBST(nums4);

    cout << "Inorder Traversal: ";
    inorder(root4);
    cout << "\nExpected: 1 2 3 4 5 6 7 8 9\n";

    cout << "Level Order Traversal:\n";
    levelOrder(root4);
    cout << endl;

    return 0;
}
