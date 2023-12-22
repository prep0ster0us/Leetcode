
/********************************************************
// 1422. Maximum Score After Splitting a String

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

*********************************************************/

class Solution {
public:
    int getScore(string s, int pivot) {
        int n= s.length();
        int score=0;
        for(int i=0; i<pivot; i++) {
            // score for left substring
            if(s[i] == '0') {
                score++;
            }
        }
        for(int i=pivot; i<n; i++) {
            // score for right substring
            if(s[i] == '1') {
                score++;
            }
        }
        return score;
    }
    int maxScore(string s) {
        int pivot=1, ans=0, n=s.length();
        while(pivot != n) {
            int score = getScore(s, pivot++);
            if(score > ans) {
                ans = score;
            }
        }
        return ans;
    }
    
};