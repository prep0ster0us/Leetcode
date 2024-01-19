/********************************************************
// 931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

TAG: Array, DP, Matrix
*********************************************************/

// DP APPROACH [Array/Matrix approach also available] \\ 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return *min_element(matrix[0].begin(), matrix[0].end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        int curr;
        // each cell captures the min path sum for each index
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(j==1) curr = min(dp[i-1][j], dp[i-1][j+1]);
                else if(j==n) curr = min(dp[i-1][j], dp[i-1][j-1]);
                else curr = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
                dp[i][j] = curr + matrix[i-1][j-1];
            }
        }
        // the final answer will the minimum path sum in the last row, across all indices (except 0 index)
        return *min_element(dp[n].begin()+1, dp[n].end());
    }
};