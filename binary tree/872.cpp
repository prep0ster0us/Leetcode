/********************************************************
// 872. Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

*********************************************************/

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
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1="",t2="";
        inOrder(root1, t1);
        inOrder(root2, t2);
        return t1==t2;
    }
    static void inOrder(TreeNode* root, string& seq) {
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) seq+=to_string(root->val)+",";
        inOrder(root->left, seq);
        inOrder(root->right, seq);
    }
};