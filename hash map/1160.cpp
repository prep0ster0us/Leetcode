/********************************************************
// 1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.
*********************************************************/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> total;
        for(char ch: chars) {
            total[ch] += 1;
        }

        int ans=0;
        for(string word : words) {
            unordered_map<char, int> temp;
            for(char ch: word) {
                temp[ch]++;
            }
            bool flag=true;
            unordered_map<char, int>::iterator itr;
            for(itr= temp.begin(); itr != temp.end(); itr++) {
                if( total[itr->first] < itr->second) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans += word.size();
            }
        }
        return ans;
    }
};