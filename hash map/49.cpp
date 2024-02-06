/********************************************************
// 49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

TAG: Array, Hash Table, String, Sorting
*********************************************************/

/* ----------- HASH TABLE - OPTIMIZED ----------------------- */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs) {
            string temp= str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto pair: mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};

/* ----------- HASH TABLE APPROACH - UNOPTIMIZED------------- */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        map<char, int> temp;
        for(string str: strs) {
            temp.clear();
            for(char ch: str) temp[ch]++;
            string key="";
            for(auto freq: temp) {
                key += freq.first;
                key += to_string(freq.second);
            }
            mp[key].push_back(str);
        }

        for(auto pair: mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};