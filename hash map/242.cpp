/********************************************************
// 242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

*********************************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1, map2;
        for(char ch: s) {
            map1[ch]++;
        }
        for(char ch: t) {
            map2[ch]++;
        }
        return map1==map2;
    }
};