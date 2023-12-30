/********************************************************
// 1155. Number of Dice Rolls With Target Sum

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, 
so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

*********************************************************/

class Solution {
public:
    const int mod= pow(10,9)+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }

    int helper(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 0 && target == 0) return 1;
        if (n == 0 || target <= 0) return 0;
        if (dp[n][target] != -1) return dp[n][target] % mod;
        dp[n][target] = 0;

        for (int i = 1; i <= k; i++) {
            dp[n][target] = (dp[n][target] + helper(n - 1, k, target - i, dp)) % mod;
        }

        return dp[n][target];
    }
};