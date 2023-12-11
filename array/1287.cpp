/********************************************************
// 1287. Element Appearing More Than 25% In Sorted Array

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

*********************************************************/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n/4;

        unordered_map<int, int> hash;
        for(int num: arr) {
            hash[num]++;
            if(hash[num] > target) {
                return num;
            }
        }
        return 0;
    }
};