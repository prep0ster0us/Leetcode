/********************************************************
// 1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

TAG: Hash Table, String, Counting
*********************************************************/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m1, m2;
        for(char ch: s) m1[ch]++;
        for(char ch: t) m2[ch]++;
        int match=0;
        unordered_map<char, int>::iterator it;
        for(it=m1.begin(); it!=m1.end(); it++) {
            if(m2.find(it->first) != m2.end()) {
                match += min(it->second, m2.find(it->first)->second);
            }
        }
        return t.length()-match;
    }
};