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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> fin;
        if(root == NULL) return fin;
        bool flag = false;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>levelElements;
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                levelElements.push_back(frontNode -> val);
                if(frontNode -> left != NULL) q.push(frontNode -> left);
                if(frontNode -> right != NULL) q.push(frontNode -> right);
            }
            if(flag){
                reverse(levelElements.begin(), levelElements.end());
            }
            fin.push_back(levelElements);
            flag = !flag;

        }
        return fin;
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

    vector<vector<int>> ans1 = sol.zigzagLevelOrder(root1);
    cout << "Zigzag Level Order Output:\n";
    print2DVector(ans1);

    cout << "Expected:\n[\n  [ 3 ]\n  [ 20 9 ]\n  [ 15 7 ]\n]\n\n";


    cout << "===== Test Case 2 (Single Node) =====\n";
    TreeNode* root2 = new TreeNode(10);

    vector<vector<int>> ans2 = sol.zigzagLevelOrder(root2);
    cout << "Zigzag Level Order Output:\n";
    print2DVector(ans2);

    cout << "Expected:\n[\n  [ 10 ]\n]\n\n";


    cout << "===== Test Case 3 (Empty Tree) =====\n";
    TreeNode* root3 = NULL;

    vector<vector<int>> ans3 = sol.zigzagLevelOrder(root3);
    cout << "Zigzag Level Order Output:\n";
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

    vector<vector<int>> ans4 = sol.zigzagLevelOrder(root4);
    cout << "Zigzag Level Order Output:\n";
    print2DVector(ans4);

    cout << "Expected:\n[\n  [ 1 ]\n  [ 3 2 ]\n  [ 4 5 6 ]\n]\n\n";


    cout << "===== Test Case 5 (Perfect Tree) =====\n";
    // Tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7
    TreeNode* root5 = new TreeNode(4);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(6);

    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(3);

    root5->right->left = new TreeNode(5);
    root5->right->right = new TreeNode(7);

    vector<vector<int>> ans5 = sol.zigzagLevelOrder(root5);
    cout << "Zigzag Level Order Output:\n";
    print2DVector(ans5);

    cout << "Expected:\n[\n  [ 4 ]\n  [ 6 2 ]\n  [ 1 3 5 7 ]\n]\n\n";

    return 0;
}
