/********************************************************
// 1662. Check if two string arrays are equivalent

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.
*********************************************************/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2; 
        for(string s: word1) {
            w1 += s;
        }
        for(string s: word2) {
            w2 += s;
        }
        return w1==w2;
    }
};