/********************************************************
// 2385. Amount of Time for Binary Tree to Be Infected

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:
    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

TAGS: Tree, DFS/BFS
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
    int ans=0;
    unordered_map<TreeNode*, TreeNode*> hash;
    unordered_set<TreeNode*> visited;
    int amountOfTime(TreeNode* root, int start) {
        // create hash map of node:parent pairs
        // and fetch start node for dfs (i.e. start node for infection)
        TreeNode* head = new TreeNode();
        getParents(root, head, start);

        // traverse the tree and keep track of infestation, and count cycles for each node
        int count=0;
        dfs(head, count);
        return ans;
    }

    void dfs(TreeNode* root, int count) {
        // if visited, check other
        if(visited.find(root) != visited.end()) return;
        // if not visited, mark as visited
        visited.insert(root);
        // update total count
        ans = max(ans, count);

        // spread infection to all adjacent nodes: left, right and parent
        if(root->left != NULL) dfs(root->left, count+1);       // left
        if(root->right != NULL) dfs(root->right, count+1);     // right
        // parent
        TreeNode* temp = hash[root];
        if(temp != NULL) {
            dfs(temp, count+1);
        }
    }

    void getParents(TreeNode* root, TreeNode* &head, int start) {
        if(root==NULL) return;
        if(root->val == start) head = root; // this is the start node for infection;
        if(root->left != NULL) {
            hash[root->left] = root;        // hash node:parent pair
            getParents(root->left, head, start);
        }
        if(root->right != NULL) {
            hash[root->right] = root;
            getParents(root->right, head, start);
        }
    }
};