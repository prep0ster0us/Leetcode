/********************************************************
// 1624. Largest Substring Between Two Equal Characters

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

*********************************************************/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        unordered_set<char> charSet(s.begin(), s.end());
        unordered_set<char>::iterator it;
        for(it=charSet.begin(); it!=charSet.end(); it++) {
            ans = max(ans, getSubLen(s, *it));
        }
        return ans;
    }
    int getSubLen(string s, char ch) {
        return s.find_last_of(ch) - s.find(ch)-1;
    }
};