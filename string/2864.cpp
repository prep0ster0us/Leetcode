/********************************************************
// 2864. Maximum Odd Binary Number

You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.
Note that the resulting string can have leading zeros.

TAG: Math, String, Greedy
*********************************************************/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(char ch: s) {
            if(ch=='1') count++;
        }
        if(count==0) return s;
        string ans(s.size(),'0');
        if(count == 1) {
            ans = ans
        }
        for(int i=0; i<(s.size()-count); i++) ans = "0"+ans;
        count--;
        for(int i=0; i<count; i++) ans = "1"+ans;
        return ans;

    }
};