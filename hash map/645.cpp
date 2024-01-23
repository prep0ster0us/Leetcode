/********************************************************
// 645. Set Mismatch

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

TAG: Array, Hash Table, Sorting, Bit Manipulation
*********************************************************/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2,0);
        unordered_map<int, int> check;
        unordered_set<int> all;

        for(int i=0; i<nums.size(); i++) {
            check[i+1]++;
            if(!all.insert(nums[i]).second) ans[0] = nums[i];
        }
        for(int i=0; i<nums.size(); i++) {
            if(all.find(i+1) == all.end()) ans[1] = i+1;
        }

        return ans;
    }
};