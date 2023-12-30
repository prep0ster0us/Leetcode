/********************************************************
// 1578. Minimum Time to Make Rope Colorful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

*********************************************************/

// GREEDY APPROACH (**CAN BE DONE WITH DP)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        char curr = colors[0];
        int maxTime = neededTime[0];

        for (int i = 1; i < neededTime.size(); i++) {
            if (curr == colors[i]) {
                // if adjacent to similar color;
                // and removal time is more than previous one; use min time one and update maxTime
                if (neededTime[i] > maxTime) {
                    sum += maxTime;
                    maxTime = neededTime[i];
                } else {
                    sum += neededTime[i];
                }
            } else {
                // if different colors, update previous color and maxTime to current position
                curr = colors[i];
                maxTime = neededTime[i];
            }
        }
        return sum;
    }
};