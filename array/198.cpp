/********************************************************
// 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

TAG: Array, DP
*********************************************************/

// ARRAY/MATRIX APPROACH [DP approach also available] \\ 

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=0, curr=0, temp;
        for(int num: nums) {
            temp = max(prev+num, curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};