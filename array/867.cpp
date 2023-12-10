/********************************************************
// 867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

*********************************************************/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        if(n == m) {
            // for square matrix, swap in-place
            int temp;
            for(int i=0; i<m; i++) {
                for(int j=i; j<n; j++) {
                    if(i != j) {
                        temp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = temp;
                    }
                }
            }
            return matrix;
        } else {
            // for mxn matrices, copy to new matrix in transpose order
            vector<vector<int>> ans(n, vector<int>(m, 0));
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    ans[j][i] = matrix[i][j];
                }
            }
            return ans;
        }
    }
};