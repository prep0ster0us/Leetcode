/********************************************************
// 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing
subsequence.
TAGS: Array, Binary Search, DP
*********************************************************/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> temp(n, 1);

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j] && temp[i] < temp[j]+1) {
                    temp[i] = temp[j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            ans = max(ans, temp[i]);
        }
        return ans;
    }
};