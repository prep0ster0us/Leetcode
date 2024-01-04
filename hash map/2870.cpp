/********************************************************
// 2870. Minimum Number of Operations to Make Array Empty

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:
    Choose two elements with equal values and delete them from the array.
    Choose three elements with equal values and delete them from the array.

Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

TAGS: Hash Table, Math, Array
*********************************************************/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int num: nums) {
            hash[num]++;
        }
        int ans=0;
        unordered_map<int, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            // single freq cannot be resolved
            if(it->second == 1) return -1;
            // max opn with groups of 3; remaining can be removed as pairs
            ans += it->second/3 + (it->second%3+1)/2;
        }
        return ans;
    }
};