/********************************************************
// 2149. Rearrange Arrya Elements by Sign

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:
    Every consecutive pair of integers have opposite signs.
    For all integers with the same sign, the order in which they were present in nums is preserved.
    The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

TAG: Array, Two Pointer, Simulation
*********************************************************/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1, q2;
        for(int num: nums) {
            if(num>0) q1.push(num);
            else q2.push(num);
        }
        vector<int> ans;
        while(q1.size()>0 && q2.size()) {
            ans.push_back(q1.front());
            ans.push_back(q2.front());
            q1.pop();
            q2.pop();
        }
        return ans;
    }
};