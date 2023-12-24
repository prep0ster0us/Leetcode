/********************************************************
// 1758. Minimum Changes To Make Alternating Binary String

You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

*********************************************************/

class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), ans1=0, ans2=0;
        vector<char> bank;
        // with 0
        bank.push_back('0');
        if(s[0]!='0') {
            ans1++;
        }
        for(int i=1; i<n; i++) {
            if(bank.back() == s[i]) {
                ans1++;
                if(s[i]=='0') {
                    bank.push_back('1');
                } else {
                    bank.push_back('0');
                }
            } else {
                bank.push_back(s[i]);
            }
        }
        bank.clear();

        // with 1
        bank.push_back('1');
        if(s[0]!='1') {
            ans2++;
        }
        for(int i=1; i<n; i++) {
            if(bank.back() == s[i]) {
                ans2++;
                if(s[i]=='0') {
                    bank.push_back('1');
                } else {
                    bank.push_back('0');
                }
            } else {
                bank.push_back(s[i]);
            }
        }
        return min(ans1, ans2);
    }
};