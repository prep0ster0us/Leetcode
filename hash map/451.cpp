/********************************************************
// 491. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

TAG: Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
*********************************************************/

class Solution {
public:
    unordered_map<char, int> mp;
    static bool comp(pair<char, int>& a, pair<char, int>& b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    string frequencySort(string s) {
        // Create freq map
        for(char ch: s) mp[ch]++;

        // Convert freq map to vector pairs and sort using custom comparator
        vector<pair<char, int>> cmpset(mp.begin(), mp.end());
        sort(cmpset.begin(), cmpset.end(), comp);

        // Create resultant string, using sorted freq mapping
        string ans="";
        for(auto pair: cmpset) ans += string(pair.second, pair.first);

        return ans;
    }
};