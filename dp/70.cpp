/********************************************************
// 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

TAG: Math, DP, Memo
*********************************************************/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) {
            return n;
        }
        // initialize dp of size (n+1) with -1
        vector<int> dp(n+1, -1);
        // push base values
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        // calculate next value (based on base values)
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};