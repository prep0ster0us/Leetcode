/********************************************************
// 977. Leaf-Similar Trees

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

TAG: Array, Two pointer, Sorting
*********************************************************/

/* SORTING APPROACH - Calculate squares and then sort the resultant array */

/* TWO POINTER APPROACH - start pointers at last negative + first positive numbers */
/* then place then in output array by comparison and move pointers accordingly till end of elements */
/* GIVEN BELOW */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j=0;
        while(j<nums.size() && nums[j]<0) j++;
        int i=j-1;
        vector<int> ans;
        while(i>=0 && j < nums.size()) {
            if(abs(nums[i]) < abs(nums[j])) {
                ans.push_back(abs(nums[i])*abs(nums[i]));
                i--;
            } else {
                ans.push_back(abs(nums[j])*abs(nums[j]));
                j++;
            }
        }
        while(j < nums.size()) {
            ans.push_back(abs(nums[j])*abs(nums[j]));
            j++;
        }
        while(i >= 0) {
            ans.push_back(abs(nums[i])*abs(nums[i]));
            i--;
        }
        return ans;
    }
};