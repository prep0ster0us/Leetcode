/********************************************************
// 931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

TAG: Array, DP, Matrix
*********************************************************/

// ARRAY/MATRIX APPROACH [DP approach also available] \\ 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return *min_element(matrix[0].begin(), matrix[0].end());

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int left = max(0, j-1);     // left index
                int right = min(n-1, j+1);  // right index
                matrix[i][j] += min(matrix[i-1][j], min(matrix[i-1][left], matrix[i-1][right]));
                // save min path sum in-place
            }
        }
        // last row contains all min path sum for each index, choose lowest
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};