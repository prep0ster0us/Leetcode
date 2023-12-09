/********************************************************
// 606. Construct String from Binary Tree

Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

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
    string tree2str(TreeNode* root) {
        string ans="";
        preOrder(root, ans);
        return ans;
    }

    void preOrder(TreeNode* root, string& s) {
        if(root == NULL) return;
        // root
        s += to_string(root->val);
        // left
        if(root->left || root->right) {
            s += "(";
            preOrder(root->left, s);
            s += ")";
        }
        // right
        if(root->right) {
            s += "(";
            preOrder(root->right, s);
            s += ")";
        }
    }
};