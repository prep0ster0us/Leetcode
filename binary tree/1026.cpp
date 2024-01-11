/********************************************************
// 1026. Maximum Difference Between Node and Ancestor

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

TAGS: Tree, DFS
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
    unordered_map<int, vector<int>> hash;
    int maxAncestorDiff(TreeNode* root) {
        getAncestors(root, -1);

        int ans=0;
        unordered_map<int, vector<int>>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            for(int num: it->second) {
                ans = max(ans, abs(it->first-num));
            }
        }
        return ans;
    }

    void getAncestors(TreeNode* root, int parent) {
        if(!root) return;
        if(parent+1){
            // parent
            hash[root->val].push_back(parent);
            // add all ancestors
            for(int num: hash[parent]) {
                hash[root->val].push_back(num);
            }
        }
        if(root->left) getAncestors(root->left, root->val);
        if(root->right) getAncestors(root->right, root->val);
    }
};