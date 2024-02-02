/********************************************************
// 2966. Divide Array Into Arrays With Max Difference

You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:
    Each element of nums should be in exactly one array.
    The difference between any two elements in one array is less than or equal to k.

Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

TAG: Array, Greedy, Sorting
*********************************************************/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i + 2 < nums.size(); i++) {
            // Check if dfference between 3rd and 2nd elements in the triplet is <= k   
            if (i % 3 == 0) {             
                if (nums[i + 2] - nums[i] <= k) {
                    // if 3 element subrange lies within difference <= k;
                    // push these elements (i, i+1, i+2)
                    ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
                } else {
                    // If not, return an empty vector- no array is possible (even when all but one satisfy)
                    return vector<vector<int>>();
                }
            }
        }
        return ans;
    }
};