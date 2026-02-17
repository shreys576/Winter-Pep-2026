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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> fin;
        if(root == NULL) return fin;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> levelElement;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                levelElement.push_back(frontNode -> val);
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            fin.push_back(levelElement[levelElement.size() - 1]);
        }
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
    //        1
    //       / \
    //      2   3
    //       \   \
    //        5   4
    //
    // Right side view: [1, 3, 4]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(4);

    vector<int> ans1 = sol.rightSideView(root1);
    cout << "Right Side View: ";
    printVector(ans1);
    cout << "Expected: [ 1 3 4 ]\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);

    vector<int> ans2 = sol.rightSideView(root2);
    cout << "Right Side View: ";
    printVector(ans2);
    cout << "Expected: [ 10 ]\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    TreeNode* root3 = NULL;

    vector<int> ans3 = sol.rightSideView(root3);
    cout << "Right Side View: ";
    printVector(ans3);
    cout << "Expected: [ ]\n\n";


    cout << "===== Test Case 4 (Left Skewed Tree) =====\n";
    // Tree:
    //    1
    //   /
    //  2
    // /
    //3
    //
    // Right view: [1,2,3]
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->left->left = new TreeNode(3);

    vector<int> ans4 = sol.rightSideView(root4);
    cout << "Right Side View: ";
    printVector(ans4);
    cout << "Expected: [ 1 2 3 ]\n\n";


    cout << "===== Test Case 5 (Perfect Tree) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    //
    // Right view: [4,6,7]
    TreeNode* root5 = new TreeNode(4);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(6);

    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(3);

    root5->right->left = new TreeNode(5);
    root5->right->right = new TreeNode(7);

    vector<int> ans5 = sol.rightSideView(root5);
    cout << "Right Side View: ";
    printVector(ans5);
    cout << "Expected: [ 4 6 7 ]\n\n";

    return 0;
}
