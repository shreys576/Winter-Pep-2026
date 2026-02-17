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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelElement;

            for(int i = 0; i < levelSize; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                levelElement.push_back(frontNode -> val);
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }

            result.push_back(levelElement); 
        }
        return result;
    }
};

// Helper function to print 2D vector
void print2DVector(vector<vector<int>> v) {
    cout << "[\n";
    for(auto level : v) {
        cout << "  [ ";
        for(int x : level) cout << x << " ";
        cout << "]\n";
    }
    cout << "]\n";
}

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

    vector<vector<int>> ans1 = sol.levelOrder(root1);
    cout << "Level Order Output:\n";
    print2DVector(ans1);
    cout << "Expected:\n[\n  [ 3 ]\n  [ 9 20 ]\n  [ 15 7 ]\n]\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);

    vector<vector<int>> ans2 = sol.levelOrder(root2);
    cout << "Level Order Output:\n";
    print2DVector(ans2);
    cout << "Expected:\n[\n  [ 10 ]\n]\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    TreeNode* root3 = NULL;

    vector<vector<int>> ans3 = sol.levelOrder(root3);
    cout << "Level Order Output:\n";
    print2DVector(ans3);
    cout << "Expected:\n[ ]\n\n";


    cout << "===== Test Case 4 =====\n";
    // Tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);

    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);

    root4->right->right = new TreeNode(6);

    vector<vector<int>> ans4 = sol.levelOrder(root4);
    cout << "Level Order Output:\n";
    print2DVector(ans4);
    cout << "Expected:\n[\n  [ 1 ]\n  [ 2 3 ]\n  [ 4 5 6 ]\n]\n\n";


    cout << "===== Test Case 5 (Skewed Tree) =====\n";
    // Tree:
    //    1
    //     \
    //      2
    //       \
    //        3
    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);

    vector<vector<int>> ans5 = sol.levelOrder(root5);
    cout << "Level Order Output:\n";
    print2DVector(ans5);
    cout << "Expected:\n[\n  [ 1 ]\n  [ 2 ]\n  [ 3 ]\n]\n\n";

    return 0;
}
