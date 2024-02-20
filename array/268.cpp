/********************************************************
// 268. Missing Number

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

TAG: Array, Math, Hash Table, Binary Search, Bit Manipulation, Sorting
*********************************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        for(int num: nums) {
            sum -= num;
        }
        return sum;
    }
};