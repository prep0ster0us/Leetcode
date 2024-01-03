/********************************************************
// 2610. Convert an Array Into a 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

    The 2D array should contain only the elements of the array nums.
    Each row in the 2D array contains distinct integers.
    The number of rows in the 2D array should be minimal.

Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

*********************************************************/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int ,int> hash;
        int maxCount=0;
        for(int num: nums) {
            // store frequency of each number
            hash[num]++;
            // keep track of max frequency
            maxCount = max(maxCount, hash[num]);
        }
        // min number of rows = max freq of a number
        // initialize 2d array with maxCount
        vector<vector<int>> ans(maxCount, vector<int>());
        map<int, int>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            // based on frequency of number, distribute across rows
            for(int i=it->second-1; i>=0; i--) {
                ans[i].push_back(it->first);
            }  
        }
        return ans;
    }
};