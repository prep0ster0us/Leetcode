/********************************************************
// 1207. Unique Number of Occurrences   

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

TAG: Array, Hash Table
*********************************************************/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> total;
        unordered_map<int, int> hash;
        for(int num: arr) {
            hash[num]++;
        }
        unordered_map<int, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            if(!total.insert(it->second).second) return false;
        }
        return true;
    }
};