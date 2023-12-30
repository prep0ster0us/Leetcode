/********************************************************
// 1531. String Compression II

Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

*********************************************************/

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.length();
        int dp[n+1][k+1];
        // base case
        for(int i=0; i<=k; i++) {
            dp[n][i] = 0;
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=k; j++) {
                // DELETE ith character
                if(j>0) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    // base case (any deletion will be better than none)
                    dp[i][j] = INT_MAX;
                }

                // KEEP the ith character
                int del_count=j;
                int freq=0;
                for(int x=i; x<n && del_count >=0; x++) {
                    // block ends at current index
                    if(s[x]==s[i]) {
                        freq++;    // keep count of length of block
                        // check length of encoded string, when DELETE and KEEP
                        // min length for each case
                        dp[i][j] = min(dp[i][j], encodeLen(freq)+dp[x+1][del_count]);
                    } else {
                        // character can be deleted
                        del_count--;
                    }
                }
            }
        }
        // final string's min length will be with k deletions and at 0th index
        // which contains min of all cases for each character (keep or remove)
        return dp[0][k];

    }
    int encodeLen(int freq){
        if(freq == 0 || freq == 1)
            return freq;
        if(freq < 10)
            return 2;
        if(freq < 100)
            return 3;
        return 4;
    }
};