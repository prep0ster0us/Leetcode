/********************************************************
// 1582. Special Positions in a Binary Matrix

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

*********************************************************/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n,0);
        vector<vector<int>> temp;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                    temp.push_back(vector<int>{i,j});
                }
            }
        }

        int ans=0;
        for(vector<int> pair: temp) {
            if(row[pair[0]] == 1 && col[pair[1]] == 1) {
                ans++;
            }
        }
        return ans;

    }
};