/********************************************************
// 1897. Redistribute Characters to Make All Strings Equal

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

*********************************************************/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        map<char, int> hash;
        // count occurrence of each character, across all words
        for(string word : words) {
            for(char ch: word) {
                hash[ch]++;
            }
        }
        // check if occurence is multiple of total number of words
        // if it is, then they can be rearranged so that each word has equal count for that character
        map<char, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            if(it->second%n!=0) {
                return false;
            }
        }
        return true;
    }
};